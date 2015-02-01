/* Proxsensor.h - Library for using the proximity sensors on the Arduino Robot
by: Tony Wu
12-14-2014
*/


#ifndef Proxsensor_h
#define Proxsensor_h

#define CM_TO_MICROSECOND	0.0343/2
#define MAX_OBST_DIST		70 //cm

class Proxsensor
{
public:
	Proxsensor(int echoPin, int trigPin, long maxDistance);
	long calcObjDistance();
	long calcObjVelocity();

private:
	static int _sensor_count;
	void sendPulse();
	long _objDistance;
	long _objVelo;
	long _prevDistance;
	long _prevVelo;
	long _maxDuration;
	int _trigPin;
	int _echoPin;

};


#endif