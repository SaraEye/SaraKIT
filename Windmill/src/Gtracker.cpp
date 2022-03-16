#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <asm/ioctl.h>
#include <linux/spi/spidev.h>
#include <iostream>		
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdbool.h>
#include "Gtracker.hpp"


//GIMBAL MOTORS
int motorDriverPin = 17;
static const int CHANNEL = 0;
int fd;

static const uint8_t     spiBPW   = 8 ;
static const uint16_t    spiDelay = 0 ;
static uint32_t    spiSpeeds [2] ;
static int         spiFds [2] ;

typedef unsigned char uchar;
uchar mHoldTorqueTimeHeader=0b01000000;
uchar mIdleTorqueHeader=0b01100000;
uchar mStopMotorsHeader=0b10000000;
uchar mGetAccelerometerVal1=0b11000000;
uchar mGetLastMotionTime=0b11010000;
uchar mResetMotorPos=0b10100000;
uchar mResetMotorPos2=0b10110000;
uchar mDefaultTimerInterval = 0b11100000;
uchar mGetMotorsPos= 0b01010000;

void sleepms(int ms){
    usleep(ms*1000);
}
static const char *spi_name = "/dev/spidev0.1";
int wiringPiSPIDataRW2(int channel, unsigned char *data, int len) {


// As usual, we begin the relationship by establishing a file object which
  //   points to the SPI device.
  int spiDev = open(spi_name, O_RDWR);
  
  // We'll want to configure our SPI hardware before we do anything else. To do
  //   this, we use the ioctl() function. Calls to this function take the form
  //   of a file descriptor, a "command", and a value. The returned value is
  //   always the result of the operation; pass it a pointer to receive a value
  //   requested from the SPI peripheral.
  
  // Start by setting the mode. If we wanted to *get* the mode, we could
  //   use SPI_IOC_RD_MODE instead. In general, the "WR" can be replaced by
  //   "RD" to fetch rather than write. Also note the somewhat awkward
  //   setting a variable rather than passing the constant. *All* data sent
  //   via ioctl() must be passed by reference!
  int mode = 0x01;
  ioctl(spiDev, SPI_IOC_WR_MODE, &mode);
  
  // The maximum speed of the SPI bus can be fetched. You'll find that, on the
  //  pcDuino, it's 12MHz.
  int maxSpeed = 0;
  ioctl(spiDev, SPI_IOC_RD_MAX_SPEED_HZ, &maxSpeed);
  //printf("Max speed: %dHz\n", maxSpeed);
  
  // In rare cases, you may find that a device expects data least significant
  //   bit first; in that case, you'll need to set that up. Writing a 0
  //   indicates MSb first; anything else indicates LSb first.
  int lsb_setting = 0;
  ioctl(spiDev, SPI_IOC_WR_LSB_FIRST, &lsb_setting);
  
  // Some devices may require more than 8 bits of data per transfer word. The
  //   SPI_IOC_WR_BITS_PER_WORD command allows you to change this; the default,
  //   0, corresponds to 8 bits per word.
  int bits_per_word = 0;
  ioctl(spiDev, SPI_IOC_WR_BITS_PER_WORD, &bits_per_word);



    struct spi_ioc_transfer spi[2];

    channel &= 1;

    // Mentioned in spidev.h but not used in the original kernel documentation
    //	test program )-:

    memset(&spi, 0, sizeof(spi));

    spi[0].tx_buf = (unsigned long)data;
    spi[0].len = len;
    spi[0].delay_usecs = spiDelay;
    spi[0].speed_hz = spiSpeeds[channel];
    spi[0].cs_change=1;
    spi[0].bits_per_word = spiBPW;

    unsigned char dummyData[4] = {0xf0, 0x00, 0x00, 0x00};
    spi[1].tx_buf = (unsigned long)dummyData;
    spi[1].rx_buf = (unsigned long)data;
    spi[1].len = len;
    spi[1].cs_change=1;
    spi[1].delay_usecs = spiDelay;
    spi[1].speed_hz = spiSpeeds[channel];
    spi[1].bits_per_word = spiBPW;

    return ioctl(spiDev, SPI_IOC_MESSAGE(2), spi);
}

//reset motor
void motorDriverReset(){
	pinMode(motorDriverPin, OUTPUT);		
	digitalWrite(motorDriverPin, 0);
	digitalWrite(motorDriverPin, 1);
}

void sendCommand(uchar *buffer, bool rw){
    if (rw)
        wiringPiSPIDataRW2(CHANNEL, buffer, 4);
    else
        wiringPiSPIDataRW(CHANNEL, buffer, 4);
}

void setIdleTorque(uchar torqueA,uchar torqueB){
    uchar cmd[4] = {mIdleTorqueHeader,torqueA, torqueB, 0x00};
    sendCommand(cmd,false);
}
    
void setIdleTorqueTime(uchar timeA,uchar timeB){
    uchar cmd[4] = {mHoldTorqueTimeHeader,timeA, timeB, 0x00};
    sendCommand(cmd,false);
}

void setDefaultTimerInterval(short interval){
	uchar intervalMSB = interval >> 8;
	uchar intervalLSB = 0xFF & interval;
	
    uchar cmd[4] = {mDefaultTimerInterval,intervalMSB, intervalLSB, 0x00};
    sendCommand(cmd,false);
}
	
void stopMotors(){
    uchar cmd[4] = {mStopMotorsHeader, 0x00, 0x00, 0x00};
    sendCommand(cmd,false);
}

unsigned int getLastMotionTime(){
    uchar cmd[4] = {mGetLastMotionTime, 0x00, 0x00, 0x00};
    sendCommand(cmd,false);
    //printf("lmt [ %x, %x, %x, %x]\n", cmd[0], cmd[1], cmd[2], cmd[3]);
    return cmd[3];
}


void resetMotorPos(){
	uchar cmd[4] = {mResetMotorPos, 0x00, 0x00, 0x00};
    sendCommand(cmd,false);
}
void resetMotorPos2(){
	uchar cmd[4] = {mResetMotorPos2, 0x00, 0x00, 0x00};
    sendCommand(cmd,false);
}

electricalMotorPos getMotorPos() {
	uchar cmd[4] = {mGetMotorsPos, 0x00, 0x00, 0x00};
    sendCommand(cmd,true);

	electricalMotorPos position;
	position.motorB = (short)cmd[0] << 8 | cmd[1];
	position.motorA = (short)cmd[2] << 8 | cmd[3];
//	printf("MotorPos A:%d, B:%d, [%x, %x, %x, %x]\n", position.motorA, position.motorB, cmd[0], cmd[1], cmd[2], cmd[3]);
	return position;
}
	
void controlMotor(int steps,uchar motorId,uchar torque,uchar speed,uchar timerSpeedControl,uchar relative){
    if (motorId==0) //todo - ustalić raz dla wszystkich to samo i wywalić!
        steps=steps*-1;
    uchar isRelative=0b00000000;
    if(relative==1)
        isRelative = 0b00100000;
    uchar direction=0;
    if(steps<0){
        direction=0b00001000;
        steps = steps * -1;
	}
    uchar motor=0;
    if(motorId==1)
        motor=0b00010000;
    uchar s=(steps>>8)&0x07;
    uchar header=isRelative|motor|direction|s;
    uchar buf1=steps&0xFF;
    if(timerSpeedControl==1)
        speed = speed + 0x80;
    uchar cmd[4] = {header, buf1, torque, speed};
//    printf("out->%x %x %x %x\n",cmd[0],cmd[1],cmd[2],cmd[3]);
    sendCommand(cmd,false);
}
void controlSpeed(uchar motorId,uchar torque,signed char speed){
    uchar direction=0;
    uchar spd=speed;
    if(speed<0){
        direction=0b10;
        spd = speed * -1;
	}
    uchar header=0b01110000;
    uchar cfg=motorId|direction;
    uchar cmd[4] = {header, cfg, torque, spd};
   // printf("out->%x %x %x %x\n",cmd[0],cmd[1],cmd[2],cmd[3]);
    sendCommand(cmd,false);
}


void tracker_init(){
    wiringPiSetup();
    fd = wiringPiSPISetupMode(CHANNEL, 100000,1);
    spiSpeeds [CHANNEL] = 100000 ;
    spiFds    [CHANNEL] = fd ;

    //Start and set position
    setIdleTorqueTime(50,255);
    sleepms(25);

   // ustaw moc poziomego powoli aby nie skoczył
    for (int i=10;i<=50;i++){
        setIdleTorque(i,i);
        sleepms(50);
    }           
}

