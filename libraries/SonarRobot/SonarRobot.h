#ifndef SonarRobot_h
#define SonarRobot_h

#include "Motor.h"
#include "Blinker.h"
#include "Proxsensor.h"

#define DATA_PIN			2
#define LATCH_PIN			4
#define CLOCK_PIN			7

#define SHFIT_DEV_COUNT		4
#define PROX_SENSOR_COUNT	3

#define FULL_PWM			255
#define PIVOT_PWM			125

#define FULL_DRIVE_DIST		500
#define PIVOT_DRIVE_DIST	160


class SonarRobot
{
public:
	SonarRobot();
	~SonarRobot();
	//Composite Classes
	Motor LeftMotor;
	Motor RightMotor;
	Blinker GreenLED;
	Blinker RedLED;
	Proxsensor SensorRight;
	Proxsensor SensorMid;
	Proxsensor SensorLeft;

	void calcMotorDrives();
	void sensorgroupPing();
	void activate();
	// void printAddress();
	
private:
	int _currentPWM;
	int _dataPin;
	int _latchPin;
	int _clockPin;
	unsigned char _dataByte;
	int _sh_device_count;
	int _p_sensor_count;
 	ShiftDevice* _sh_devices[SHFIT_DEV_COUNT]; //must declare size so prevent _p_sensor from overwriting address of _sh_device
 	Proxsensor* _p_sensors[PROX_SENSOR_COUNT];
	void collectBytes();
	void shiftBytes();
    
};


#endif