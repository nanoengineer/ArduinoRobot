/* Proxsensor.h - Library for using the proximity sensors on the Arduino Robot
by: Tony Wu
12-14-2014
*/


#ifndef Proxsensor_h
#define Proxsensor_h

#include "Arduino.h"

class Proxsensor
{
public:
	Proxsensor(int echoPin, int trigPin, long maxDistance);
	long getDistance(); 

	long distance;
	long maxDistance;

private:
	int _trigPin;
	int _echoPin;
	long cmToMicroSecond;
};


#endif