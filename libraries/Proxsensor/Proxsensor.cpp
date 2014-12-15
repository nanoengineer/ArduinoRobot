/* Proxsensor.cpp - Library for using the proximity sensors on the Arduino Robot
by: Tony Wu
12-14-2014
*/

#include "Arduino.h"
#include "Proxsensor.h"


//Initializes a Proxsensor instance with proper pin configs and the maximum detection distance
Proxsensor::Proxsensor(int echoPin, int trigPin, long maxDis)
{
	pinMode(echoPin, INPUT);
	pinMode(trigPin, OUTPUT);
	_trigPin = trigPin;
	_echoPin = echoPin;
	maxDistance = maxDist;
	cmToMicroSecond = 0.0343/2;
}

long Proxsensor::getDistance()
{
	//send Pulse
	digitalWrite(trigPin,LOW);
	delayMicroseconds(4);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	//receive Pulse
	long maxDuration = maxDistance / cmToMicroSecond; 
	long duration = pulseIn(echoPin, HIGH, maxDuration);
	if(duration == 0){
		duration = maxDuration;
	}
	distance = duration * cmToMicroSecond;
	return distance;
}

