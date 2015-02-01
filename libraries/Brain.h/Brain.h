/* Brain.h - Library for anonymous control of the arduino robot
by: Tony Wu
12-14-2014
*/

#ifndef Brain_h
#define Brain_h

#define NUM_MOTRS			2
#define	NUM_LEDS			2
#define NUM_PROXSENSORS		3

#define SENSOR_M_ECHO_PIN	12
#define SENSOR_M_TRIG_PIN	13
#define SENSOR_L_ECHO_PIN	8
#define SENSOR_L_TRIG_PIN	10
#define SENSOR_R_ECHO_PIN	9
#define SENSOR_R_TRIG_PIN	11

#define MOTOR_L_PIN			6
#define MOTOR_R_PIN			5

#define DATA_PIN			2
#define LATCH_PIN			4
#define CLOCK_PIN			7


#define 

class Brain
{
public:
	Brain(int mode); //0 - remoteo control 1 - auto, 2 - auto PID,
	~Brain();

	void initComponents(int num_motors, int num_leds, int num_proxsensors);
	void calculateIO();
	void setCommands();
	void runCommands();
	/* data */
private:
	int _mode;
	int _num_motors;
	int _num_leds;
	int _num_proxsensors;
};

#endif