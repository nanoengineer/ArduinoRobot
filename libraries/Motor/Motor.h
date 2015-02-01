/* Motors.h - Library for using the L293D motor driver on the Arduino Robot
by: Tony Wu
12-14-2014
*/

#ifndef Motor_h
#define Motor_h

class Motor
{
public:
	Motor(int drivePin);
	~Motor();
	void setPolarPWM(int polarPWM); 
	void run();
	void off();
	int getMotorCount();

private:
	int _motor_count;
	int _drivePin;
	int _polarPWM;
};





#endif