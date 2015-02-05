/* Motors.h - Library for using the L293D motor driver on the Arduino Robot
by: Tony Wu
12-14-2014
*/

#ifndef Motor_h
#define Motor_h

#include "ShiftDevice.h"

#define LEFT_DRIVE_PIN		6
#define RIGHT_DRIVE_PIN		5
#define LEFT_BYTE			B00000100
#define LEFT_MASK			~((LEFT_BYTE)|(LEFT_BYTE << 1))
#define RIGHT_BYTE			B00000001
#define RIGHT_MASK			~((RIGHT_BYTE)|(RIGHT_BYTE << 1))

class Motor : public ShiftDevice
{
public:
	Motor(int drivePin);
	~Motor();
	void setPolarPWM(int polarPWM); 
	void run();
	void off();
	static int getMotorCount();
private:
	static int _motor_count;
	int _drivePin;
	int _polarPWM;
};
#endif