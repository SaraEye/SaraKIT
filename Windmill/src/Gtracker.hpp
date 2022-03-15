#ifndef _TRACKER_H_
#define _TRACKER_H_

#include <numeric>
typedef unsigned char uchar;
struct accData{
	int x1;
	int x2;
};

struct electricalMotorPos {
	short motorA;
	short motorB;
};


void tracker_init();
void tracker_deinit();
void setIdleTorque(uchar torqueA,uchar torqueB);
void tracker_pause();
bool isTrackerRunning();
float getAngleX();
float getAngleY();
int ACCGetYangle();
unsigned int getLastMotionTime();
electricalMotorPos getMotorPos();
void setIdleTorque(uchar torqueA,uchar torqueB);
void controlMotor(int steps,uchar motorId,uchar torque,uchar speed,uchar timerSpeedControl,uchar relative);


#endif // _TRACKER_H_
