//Blinker.h - class library for LEDs on the Arduino Robot

#ifndef Blinker_h
#define Blinker_h

#include "ShiftDevice.h"
#include "Arduino.h"

#define GREEN_BYTE 	B00010000
#define GREEN_MASK 	~(GREEN_BYTE)
#define RED_BYTE 	B00100000
#define RED_MASK 	~(RED_BYTE)

class Blinker : public ShiftDevice
{
public:
	Blinker(char color);
	~Blinker();

	void on();
	void off();
	static int getBlinkerCount();

	/* data */
private:
	static int _led_count;
	bool _ledstate;
};


#endif