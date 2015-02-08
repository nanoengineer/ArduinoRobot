//ShiftDevice.cpp - class library for all robot devices controlled by the shift register
#include "ShiftDevice.h"
#include "Arduino.h"

int ShiftDevice::_shift_device_count;

ShiftDevice::ShiftDevice(){
	_shift_device_count++;
}

unsigned char ShiftDevice::getActiveByte()
{
	return _activeByte;
}

unsigned char ShiftDevice::getMask()
{
	return _mask;
}

int ShiftDevice::getShiftDeviceCount()
{
	return _shift_device_count;
}

ShiftDevice::~ShiftDevice(){
}
