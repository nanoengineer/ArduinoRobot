//Motor.cpp 

#include "Arduino.h"
#include "Motor.h"

int Motor::_motor_count;

Motor::Motor(int drivePin)
{
	pinMode(drivePin, OUTPUT);
	int _drivePin = drivePin;
	_motor_count++;
	analogWrite(_drivePin, 0); //Off by default
}

void Motor::setPolarPWM(int polarPWM)
{
	_polarPWM = polarPWM;
}

void Motor::run() 
{
	analogWrite(_drivePin, _polarPWM);
}

void Motor::off() 
{
	analogWrite(_drivePin, 0);
}

int Motor::getMotorCount() 
{
	return _motor_count;
}

Motor::~Motor(){};