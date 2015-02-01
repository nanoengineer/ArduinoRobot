//Blinker.h - class library for LEDs on the Arduino Robot

#ifndef Blinker_h
#define Blinker_h

#include "Arduino.h"

class Blinker
{
public:
	Blinker();
	~Blinker();

	void setLedBit();
	/* data */
private:
	static int led_count;
	char ledBit;

};



#endif