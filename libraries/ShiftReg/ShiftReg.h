#ifndef ShiftReg_h
#define ShiftReg_h

#define RIGHT_MOTOR_BIT_P	B00000001
#define RIGHT_MOTOR_BIT_N	B00000010
#define LEFT_MOTOR_BIT_P	B00000100
#define LEFT_MOTOR_BIT_N	B00001000
#define GREEN_LED_BIT		B00010000	
#define RED_LED_BIT			B00100000

class ShiftReg
{
public:
	ShiftReg(int dataPin, int latchPin, int clockPin);
	~ShiftReg();

	void setData();
	void shiftData();

private:
	int _dataPin;
	int _latchPin;
	int _clockPin;
	char _dataByte;

	/* data */
};


#endif