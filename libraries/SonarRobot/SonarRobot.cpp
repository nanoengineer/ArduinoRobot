#include "ShiftReg.h"
#include "ShiftDevice.h"
#include "Motor.h"
#include "Blinker.h"
#include "Arduino.h"


int ShiftReg::_shiftreg_count; 
	
ShiftReg::ShiftReg(int dataPin, int latchPin, int clockPin) : LeftMotor(LEFT_DRIVE_PIN), RightMotor(RIGHT_DRIVE_PIN), GreenLED('G'), RedLED('R')
{
	_dataPin = dataPin;
	_latchPin = latchPin;
	_clockPin = clockPin;
	pinMode(_dataPin, OUTPUT);
	pinMode(_latchPin, OUTPUT);
	pinMode(_clockPin, OUTPUT);
	_dataByte = B00000000;
	_total_device_count = Motor::getMotorCount() + Blinker::getBlinkerCount();

}

void ShiftReg::collectData()
{
	ShiftDevice* devices[6] = {&LeftMotor, &RightMotor, &GreenLED, &RedLED};
	//ShiftDevice* devices[6] = {&RedLED};

	for(int i = 0; i < _total_device_count; i++ )
	{
	//for(int i = 0; i < 2; i++ ){
		// Serial.print("Initial databyte: ");
		// Serial.println(_dataByte, BIN);
		// Serial.print("mask: ");
		// Serial.println(devices[i]->getMask(), BIN);
		// Serial.print("mask AND data: ");
		// Serial.println(((_dataByte) & (devices[i]->getMask())), BIN);
		// Serial.print("active byte: ");
		// Serial.println((devices[i]->getActiveByte()), BIN);
		// Serial.print("mask AND data OR active: ");
		// Serial.println(((_dataByte) & (devices[i]->getMask()))|(devices[i]->getActiveByte()), BIN);
		// Serial.println("Next Device.");
		_dataByte = ((_dataByte) & (devices[i]->getMask()))|(devices[i]->getActiveByte());
	}
	Serial.print("Final Data Byte: ");
	Serial.println(_dataByte, BIN);

}

void ShiftReg::shiftData() 
{
	digitalWrite(_latchPin, LOW);
	shiftOut(_dataPin, _clockPin, LSBFIRST, _dataByte);
	digitalWrite(_latchPin, HIGH);	
}

int ShiftReg::getShiftRegCount() 
{
	return _shiftreg_count;
}

ShiftReg::~ShiftReg(){}
