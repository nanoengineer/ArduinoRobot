//Motor.cpp 

#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int drivePin)
{
	_motor_count = 0;
	pinMode(drivePin, OUTPUT);
	int _drivePin = drivePin;
	_motor_count++;
}

Motor::setPolarPWM(int PolarPWM)
{
	_polarPWM = polarPWM
}

Motor::Run() 
{
	analogWrite(_drivePin, _polarPWM);
}

static int Motor::getMotorCount() 
{
	return _motor_count;
}
Motor::~Motor(){};