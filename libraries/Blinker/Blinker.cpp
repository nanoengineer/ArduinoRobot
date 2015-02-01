#include "Blinker.h"

Blinker::Blinker() 
{  	_led_count = 0;
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
	return Blinker::_led_count;
};


Blinker::~Blinker() 
{}
