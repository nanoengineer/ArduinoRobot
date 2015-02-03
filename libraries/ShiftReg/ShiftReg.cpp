#include "ShiftReg.h"
#include "Arduino.h"

int ShiftReg::_shiftreg_count;
	
ShiftReg::ShiftReg(int dataPin, int latchPin, int clockPin)
{
	_dataPin = dataPin;
	_latchPin = latchPin;
	_clockPin = clockPin;
	pinMode(_dataPin, OUTPUT);
	pinMode(_latchPin, OUTPUT);
	pinMode(_clockPin, OUTPUT);
	_dataByte = B00000000;
}

void ShiftReg::setData(char data) 
{
	_dataByte = data;
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
