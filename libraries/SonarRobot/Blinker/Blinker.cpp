#include "Blinker.h"
#include "ShiftDevice.h"

int Blinker::_led_count;

Blinker::Blinker(char color) 
{  	
	if(color == 'G' || color == 'g')
	{
		_controlByte = GREEN_BYTE;
		_mask = GREEN_MASK;
	}

	else if(color == 'R' || color == 'r') //WHY DOES THIS NOT WORK WHEN IT'S AN ELSE IF.
	{
		_controlByte = RED_BYTE;
		_mask = RED_MASK;
	}

	_activeByte = 0;
	_led_count++;
}

void Blinker::on()
{	
	_activeByte = _controlByte;
	_ledstate = true;
}

void Blinker::off()
{
	_activeByte = 0;
	_ledstate = false;
}

int Blinker::getBlinkerCount()
{
	return _led_count;
};

Blinker::~Blinker() 
{}
