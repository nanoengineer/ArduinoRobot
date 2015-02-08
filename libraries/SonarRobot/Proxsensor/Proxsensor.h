/* Proxsensor.h - Library for using the proximity sensors on the Arduino Robot
by: Tony Wu
12-14-2014
*/


#ifndef Proxsensor_h
#define Proxsensor_h

#define SPEED_OF_SOUND		0.340 // mm/us
#define MAX_DIST			700   //mm
#define SAMPLE_INT			100000

#define MID_ECHO_PIN		12
#define MID_TRIG_PIN		13
#define LEFT_ECHO_PIN		8
#define LEFT_TRIG_PIN		10
#define RIGHT_ECHO_PIN		9
#define RIGHT_TRIG_PIN		11

class Proxsensor
{
public:
	Proxsensor(int echoPin, int trigPin, int maxDistance);
	~Proxsensor();
	void sendPulse();
	void rcvPulse();
	int calcObjDistance();
	int calcObjVelocity();
	int calcObjAccel();
	static int getProxsensorCount();

private:
	static int _proxsensor_count;
	int _objDist; //mm
	int _objVelo;	//mm/us
	int _prevDist;
	int _prevVelo;
	int _objAccel; //mm/us^2
	unsigned long _duration; //us
	unsigned long _maxDura;  //us
	int _maxDist; //mm
	int _sampleInterval; //us
	int _trigPin;
	int _echoPin;

};


#endif