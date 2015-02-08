#include "SonarRobot.h"
#include "Arduino.h" 

SonarRobot::SonarRobot() : LeftMotor(LEFT_DRIVE_PIN), RightMotor(RIGHT_DRIVE_PIN), GreenLED('G'), RedLED('R'), SensorMid(MID_ECHO_PIN,MID_TRIG_PIN,MAX_DIST), SensorLeft(LEFT_ECHO_PIN,LEFT_TRIG_PIN,MAX_DIST), SensorRight(RIGHT_ECHO_PIN,RIGHT_TRIG_PIN,MAX_DIST)
{
	_dataPin = DATA_PIN;
	_latchPin = LATCH_PIN;
	_clockPin = CLOCK_PIN;
	pinMode(_dataPin, OUTPUT);
	pinMode(_latchPin, OUTPUT);
	pinMode(_clockPin, OUTPUT);
	_dataByte = B00000000;
	_sh_device_count = ShiftDevice::getShiftDeviceCount();
	_p_sensor_count = Proxsensor::getProxsensorCount();

	_sh_devices[0] = &LeftMotor;
	_sh_devices[1] = &RightMotor;
	_sh_devices[2] = &GreenLED;
	_sh_devices[3] = &RedLED;

	_p_sensors[0] =	&SensorLeft;
	_p_sensors[1] = &SensorRight;
	_p_sensors[2] = &SensorMid;

	_currentPWM = 0;

}

void SonarRobot::calcMotorDrives()
{
	int d_left,d_right,d_mid;
	int* dists[3] =  {&d_left, &d_right, &d_mid};

	for(int i = 0 ; i<_p_sensor_count; i++)
	{
		*(dists[i]) = _p_sensors[i]->calcObjDistance();
	}

	int l_pwm;
	int r_pwm;

	if(d_left >= FULL_DRIVE_DIST && d_right >= FULL_DRIVE_DIST && d_mid >= FULL_DRIVE_DIST)
	{
		l_pwm = FULL_PWM;
		r_pwm = FULL_PWM;
		_currentPWM = FULL_PWM;
		GreenLED.on();
		RedLED.off();
	}

	if((d_mid < FULL_DRIVE_DIST && d_mid > PIVOT_DRIVE_DIST)|| (d_left < FULL_DRIVE_DIST && d_left > PIVOT_DRIVE_DIST) || (d_right < FULL_DRIVE_DIST && d_right > PIVOT_DRIVE_DIST))
	{
		int avrg_dist = (d_mid + d_left + d_right)/3;
		_currentPWM = map(avrg_dist, PIVOT_DRIVE_DIST, 640, PIVOT_PWM, FULL_PWM);
		l_pwm = _currentPWM;
		r_pwm = _currentPWM;
		GreenLED.on();
		RedLED.on();

	}

	if(d_left < PIVOT_DRIVE_DIST || d_right < PIVOT_DRIVE_DIST || d_mid < PIVOT_DRIVE_DIST)
	{
		if(d_left > d_right)
		{
			l_pwm = -PIVOT_PWM;
			r_pwm = PIVOT_PWM;
		}
		else if(d_left < d_right)
		{
			l_pwm = PIVOT_PWM+50;
			r_pwm = -PIVOT_PWM-50;
		}
		else{
			l_pwm = -PIVOT_PWM;
			r_pwm = PIVOT_PWM;
		}

		_currentPWM = 0;

		GreenLED.off();
		RedLED.on();

	}

	LeftMotor.setPolarPWM(l_pwm);
	RightMotor.setPolarPWM(r_pwm);
}

void SonarRobot::sensorgroupPing()
{
	for(int i = 0 ; i<_p_sensor_count; i++)
	{
		_p_sensors[i]->sendPulse();
		_p_sensors[i]->rcvPulse();
	}
}

void SonarRobot::activate()
{	
	LeftMotor.run();
	RightMotor.run();
	collectBytes();
	shiftBytes();
}

void SonarRobot::collectBytes()
{
	
	for(int i = 0; i < _sh_device_count; i++)
	{
		_dataByte = ((_dataByte) & (_sh_devices[i]->getMask()))|(_sh_devices[i]->getActiveByte());
	}
	// Serial.print("Final Data Byte: ");
	// Serial.println(_dataByte, BIN);
}

void SonarRobot::shiftBytes() 
{
	digitalWrite(_latchPin, LOW);
	shiftOut(_dataPin, _clockPin, LSBFIRST, _dataByte);
	digitalWrite(_latchPin, HIGH);	
}

// void SonarRobot::printAddress(){
// 		Serial.println((int)&_sh_devices, HEX);
// 		Serial.println((int)&_p_sensors, HEX);

// }

SonarRobot::~SonarRobot(){}

	// 	Serial.print("Initial databyte: ");
	// 	Serial.println(_dataByte, BIN);
	// 	Serial.print("mask: ");
	// 	Serial.println(_sh_devices[i]->getMask(), BIN);
	// 	Serial.print("mask AND data: ");
	// 	Serial.println(((_dataByte) & (_sh_devices[i]->getMask())), BIN);
	// 	Serial.print("active byte: ");
	// 	Serial.println((_sh_devices[i]->getActiveByte()), BIN);
	// 	Serial.print("mask AND data OR active: ");
	// 	Serial.println(((_dataByte) & (_sh_devices[i]->getMask()))|(_sh_devices[i]->getActiveByte()), BIN);
	// Serial.println("Next Device.");