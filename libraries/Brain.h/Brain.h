/* Brain.h - Library for anonymous control of the arduino robot
by: Tony Wu
12-14-2014
*/

#ifndef Brain_h
#define Brain_h

// #include "Arduino.h"
// #include "Motor.h"
// #include "Blinker.h"
// #include "Proxsensor.h"
// #include "ShiftReg.h"

#define NUM_MOTRS		2
#define	NUM_LEDS		2
#define NUM_PROXSENSORS	3

class Brain
{
public:
	Brain(arguments);
	~Brain();

	void setCommand();
	void runCommand();
	/* data */
};

#endif