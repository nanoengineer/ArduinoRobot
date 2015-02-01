/* Proxsensor.cpp - Library for using the proximity sensors on the Arduino Robot
by: Tony Wu
12-14-2014
*/

#include "Arduino.h"
#include "Proxsensor.h"

//Initializes a Proxsensor instance with proper pin configs and the maximum detection distance
Proxsensor::Proxsensor(int echoPin, int trigPin, int maxDist) {
	_proxsensor_count = 0;
	_trigPin = trigPin;
	_echoPin = echoPin;
	pinMode(_echoPin, INPUT_PULLUP);
	pinMode(_trigPin, OUTPUT);
	_maxDist = maxDist;
	_objDist = 0;
	_objVelo = 0;
	_maxDura = (2 * maxDist) / SPEED_OF_SOUND; 
	_sampleInterval = 4000;
	_proxsensor_count++;
}

int Proxsensor::calcObjDistance()
{	
	//send Pulse
	sendPulse();
	//receive Pulse
	unsigned long duration = pulseIn(_echoPin, HIGH, _maxDura); //pulseIn will return 0 if no signal is received within maxDuration period
	if(duration == 0){
		duration = _maxDura;
	}

	_prevDist = _objDist;
	_objDist = (2 * duration) * SPEED_OF_SOUND;
	return _objDist;
}

int Proxsensor::calcObjVelocity()
{
	_prevVelo = _objVelo;
	_objVelo = (_prevDist - _objDist)/_sampleInterval;
	return _objVelo;
}

int Proxsensor::calcObjAccel()
{
	_objAccel = (_prevVelo - _objVelo)/_sampleInterval;
	return _objAccel;
}


void Proxsensor::sendPulse()
{
	digitalWrite(_trigPin,LOW);
	delayMicroseconds(4);
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trigPin, LOW);
}

int Proxsensor::getProxsensorcount()
{
	return _proxsensor_count;
};

Proxsensor::~Proxsensor(){}