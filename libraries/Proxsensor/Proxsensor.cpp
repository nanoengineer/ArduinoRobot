/* Proxsensor.cpp - Library for using the proximity sensors on the Arduino Robot
by: Tony Wu
12-14-2014
*/

#include "Arduino.h"
#include "Proxsensor.h"

#define SPEED_OF_SOUND		0.340 // mm/us

//Initializes a Proxsensor instance with proper pin configs and the maximum detection distance
Proxsensor::Proxsensor(int echoPin, int trigPin, int maxDis) {
	pinMode(echoPin, INPUT_PULLUP);
	pinMode(trigPin, OUTPUT);
	_trigPin = trigPin;
	_echoPin = echoPin;
	_maxDist = maxDist;
	_objDist = 0;
	_objVelo = 0;
	_maxDura = (2 * maxDist) / SPEED_OF_SOUND; 

}

int Proxsensor::calcObjDistance()
{	
	//send Pulse
	sendPulse();
	//receive Pulse
	unsigned long duration = pulseIn(echoPin, HIGH, _maxDura); //pulseIn will return 0 if no signal is received within maxDuration period
	if(duration == 0){
		(int) duration = _maxDura;
	}

	_prevDist = _objDist;
	_objDist = (2 * diration) * SPEED_OF_SOUND;
	return _objDist;
}

int Proxsensor::calcObjVelocity()
{
	_prevVelo = _objVelo;
	_objVelo = (_prevDist - _objDist)/sampleInterval;
	return _objVelo;
}

int Proxsensor::calcObjAccel()
{
	_objAccel = (_prevVelo - _objVelo)/sampleInterval;
	return _objAccel;
}


void sendPulse()
{
	digitalWrite(trigPin,LOW);
	delayMicroseconds(4);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
}

Proxsensor::~Proxsensor(){}