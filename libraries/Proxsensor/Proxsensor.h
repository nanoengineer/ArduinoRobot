/* Proxsensor.h - Library for using the proximity sensors on the Arduino Robot
by: Tony Wu
12-14-2014
*/


#ifndef Proxsensor_h
#define Proxsensor_h

#define SPEED_OF_SOUND		0.340 // mm/us
#define MAX_DIST			700   //mm

class Proxsensor
{
public:
	Proxsensor(int echoPin, int trigPin, int maxDistance);
	~Proxsensor();
	int calcObjDistance();
	int calcObjVelocity();
	int calcObjAccel();
	static int getProxsensorcount();

private:
	static int _proxsensor_count;
	int _objDist; //mm
	int _objVelo;	//mm/us
	int _prevDist;
	int _prevVelo;
	int _objAccel;
	unsigned long _maxDura;
	int _maxDist;
	int _trigPin;
	int _echoPin;
	int _sampleInterval; //us
	void sendPulse();
};


#endif