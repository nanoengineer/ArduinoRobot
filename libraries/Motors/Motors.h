/* Motors.h - Library for using the L293D motor driver on the Arduino Robot
by: Tony Wu
12-14-2014
*/

#ifndef Motors_h
#define Motors_h

#include "Arduino.h"
#include "Proxsensor.h"

class Motor
{
public:
	Motors(int drivePin);
	void setVelocity(int velocity);
	void autoVelocity();
	

private:
	int _drivePin;


};





#endif