#include "Blinker.h"

int Blinker::_led_count;

Blinker::Blinker() 
{  	
	_led_count++;
}

bool Blinker::on()
{
	_ledstate = true;
	return true;
}

bool Blinker::off()
{
	_ledstate = false;
	return false;
}

int Blinker::getLedCount()
{
	return _led_count;
};


Blinker::~Blinker() 
{}
