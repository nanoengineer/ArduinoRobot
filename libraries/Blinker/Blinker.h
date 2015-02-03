//Blinker.h - class library for LEDs on the Arduino Robot

#ifndef Blinker_h
#define Blinker_h

class Blinker
{
public:
	Blinker();
	~Blinker();

	bool on();
	bool off();
	static int getLedCount();
	/* data */
private:
	static int _led_count;
	bool _ledstate;

};



#endif