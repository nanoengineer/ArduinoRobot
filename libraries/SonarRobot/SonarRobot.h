#ifndef ShiftReg_h
#define ShiftReg_h
	
#include "Motor.h"
#include "Blinker.h"

#define DATA_PIN			2
#define LATCH_PIN			4
#define CLOCK_PIN			7

class ShiftReg
{
public:
	ShiftReg(int dataPin, int latchPin, int clockPin);
	~ShiftReg();
	Motor LeftMotor;
	Motor RightMotor;
	Blinker GreenLED;
	Blinker RedLED;

	void collectData();
	void shiftData();
	static int getShiftRegCount();
	
private:
	static int _shiftreg_count;
	int _dataPin;
	int _latchPin;
	int _clockPin;
	unsigned char _dataByte;
	unsigned int _total_device_count;
};


#endif