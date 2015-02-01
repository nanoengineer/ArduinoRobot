//Motor.cpp 

#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int drivePin)
{
	_motor_count = 0;
	pinMode(drivePin, OUTPUT);
	int _drivePin = drivePin;
	_motor_count++;
	analogWrite(_drivePin, 0); //Off by default
}

Motor::setPolarPWM(int PolarPWM)
{
	_polarPWM = polarPWM
}

Motor::run() 
{
	analogWrite(_drivePin, _polarPWM);
}

Motor::off() 
{
	analogWrite(_drivePin, 0);
}

static int Motor::getMotorCount() 
{
	return _motor_count;
}
Motor::~Motor(){};