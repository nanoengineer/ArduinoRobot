/* Proxsensor.cpp - Library for using the proximity sensors on the Arduino Robot
by: Tony Wu
12-14-2014
*/

#include "Arduino.h"
#include "Proxsensor.h"

//Initializes a Proxsensor instance with proper pin configs and the maximum detection distance
Proxsensor::Proxsensor(int echoPin, int trigPin, long maxDis) {
	pinMode(echoPin, INPUT);
	pinMode(trigPin, OUTPUT);
	_trigPin = trigPin;
	_echoPin = echoPin;
	maxDistance = maxDist;
}

long Proxsensor::getDistance()
{
	_maxDuration = maxDistance / CM_TO_MICROSECOND; 

	//send Pulse
	sendPulse();

	//receive Pulse
	long duration = pulseIn(echoPin, HIGH, maxDuration); //pulseIn will return 0 if no signal is received within maxDuration period
	if(duration == 0){
		duration = maxDuration;
	}
	distance = duration * CM_TO_MICROSECOND;
	return distance;
}

void sendPulse() {
	digitalWrite(trigPin,LOW);
	delayMicroseconds(4);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
}

Proxsensor::~Proxsensor(){}