//Brain.cpp

#include "Arduino.h"
#include "Brain.h"
#include "Motor.h"
#include "ShiftDevice.h"
#include "ShiftReg.h"

Brain::Brain( int mode ) {
	_mode = mode;
}

Brain::~Brain() {
	
}