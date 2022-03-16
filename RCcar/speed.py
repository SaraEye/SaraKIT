import spidev
import time

bus=0
device=1
spi = spidev.SpiDev()
spi.open(bus, device)
spi.mode = 0b01
spi.max_speed_hz = 1000000


def setSteps(steps):

    isRelative = 0b00100000
    direction=0
    torque=50
    if steps<0:
        direction=0b00001000
        steps = steps * -1
	
    motor=0b00010000
    s=(steps>>8)&0x07
    header=isRelative|motor|direction|s
    buf1=steps&0xFF
    cmd=[header, buf1, torque, 100]

    to_send=[]
    to_send.extend(cmd)
    for i in range(0,len(to_send),4):
        ts=[to_send[i],to_send[i+1],to_send[i+2],to_send[i+3]]
        spi.xfer(ts)

def setSpeed(speed):    
    direction=0
    spd=speed
    motorId=1
    torque=50
    if speed<0:
        direction=0b10
        spd = speed * -1
	
    header=0b01110000
    cfg=motorId|direction
    cmd = [header, cfg, torque, spd]
    to_send=[]
    to_send.extend(cmd)
    for i in range(0,len(to_send),4):
        ts=[to_send[i],to_send[i+1],to_send[i+2],to_send[i+3]]
        spi.xfer(ts)



setSpeed(100)


spi.close()


