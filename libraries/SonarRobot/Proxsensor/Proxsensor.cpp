/* Proxsensor.cpp - Library for using the proximity sensors on the Arduino Robot
by: Tony Wu
12-14-2014
*/

#include "Arduino.h"
#include "Proxsensor.h"


#define PrL(x) Serial.println(x);
#define Pr(x) Serial.print(x);

int Proxsensor::_proxsensor_count; //definition of static variable

//Initializes a Proxsensor instance with proper pin configs and the maximum detection distance
Proxsensor::Proxsensor(int echoPin, int trigPin, int maxDist) {
	_trigPin = trigPin;
	_echoPin = echoPin;
	pinMode(_echoPin, INPUT_PULLUP);
	pinMode(_trigPin, OUTPUT);
	_maxDist = maxDist;
	_objDist = 0;
	_objVelo = 0;
	_maxDura = (2 * maxDist) / SPEED_OF_SOUND; 
	_sampleInterval = SAMPLE_INT;
	_proxsensor_count++;
}

void Proxsensor::sendPulse()
{
	digitalWrite(_trigPin,LOW);
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trigPin, LOW);
}

void Proxsensor::rcvPulse()
{
	_duration = pulseIn(_echoPin, HIGH, _maxDura); //pulseIn will return 0 if no signal is received within maxDuration period
	if(_duration == 0){
		_duration = _maxDura;
	}
}

int Proxsensor::calcObjDistance()
{	
	_prevDist = _objDist;
	_objDist = (int) (_duration/2) * SPEED_OF_SOUND;
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

int Proxsensor::getProxsensorCount()
{
	return _proxsensor_count;
};

Proxsensor::~Proxsensor(){}