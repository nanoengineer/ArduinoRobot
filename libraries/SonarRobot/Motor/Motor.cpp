//Motor.cpp 

#include "Arduino.h"
#include "Motor.h"

int Motor::_motor_count;

Motor::Motor(int drivePin)
{	
	if(drivePin == LEFT_DRIVE_PIN)
	{
		_controlByte = LEFT_BYTE;
		_mask = LEFT_MASK;
	}
	else if(drivePin == RIGHT_DRIVE_PIN)
	{
		_controlByte = RIGHT_BYTE;
		_mask = RIGHT_MASK;
	}
	pinMode(drivePin, OUTPUT);
	_drivePin = drivePin;
	
	_motor_count++;
	_activeByte = 0;
	analogWrite(_drivePin, 0); //Ensure off by default
}

void Motor::setPolarPWM(int polarPWM)
{
	_polarPWM = polarPWM;

	if(_polarPWM > 0)
	{
		_activeByte = (_controlByte) << 0;
	}
	else if(_polarPWM < 0)
	{
		_activeByte = (_controlByte) << 1;
	}
	else 
	{
		_activeByte = 0;
	}
}

void Motor::run() 
{
	analogWrite(_drivePin, abs(_polarPWM));
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