//Brain.cpp

#include "Arduino.h"
#include "Brain.h"
#include "Motor.h"
#include "Blinker.h"
#include "Proxsensor.h"
#include "ShiftReg.h"

Brain::Brain( int mode ) {
	_mode = mode;
}

bool initComponents()

Brain::~Brain() {
	
}