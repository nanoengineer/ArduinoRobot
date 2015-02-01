#include "ShiftReg.h"
#include "Arduino.h"

	
ShiftReg::ShiftReg(int dataPin, int latchPin, int clockPin)
{
	_dataPin = dataPin;
	_latchPin = latchPin;
	_clockPin = clockPin;
	_dataByte = B00000000;
}

void ShiftReg::collectData(data) 
{
	_dataByte = data;
}

void ShiftReg::shiftData() 
{
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, _dataByte);
	digitalWrite(latchPin, HIGH);	
}

hiftReg::~ShiftReg(){}
