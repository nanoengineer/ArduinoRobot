//ShiftDevice.cpp - class library for all robot devices controlled by the shift register
#include "ShiftDevice.h"
#include "Arduino.h"


ShiftDevice::ShiftDevice(){
}

unsigned char ShiftDevice::getActiveByte()
{
	return _activeByte;
}

unsigned char ShiftDevice::getMask()
{
	return _mask;
}

ShiftDevice::~ShiftDevice(){
}
