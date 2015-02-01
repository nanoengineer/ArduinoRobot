/* Motors.h - Library for using the L293D motor driver on the Arduino Robot
by: Tony Wu
12-14-2014
*/

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"
#include "Proxsensor.h"
#include "ShiftReg.h"

class Motor
{
public:
	Motors(int drivePin);
	~Motors();
	void setPolarPWM(int polarPWM); 

private:
	static int motor_count;
	int _drivePin;
	int _polarPWM;
};





#endif