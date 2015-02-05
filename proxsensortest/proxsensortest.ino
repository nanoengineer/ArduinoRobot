
#include "Proxsensor.h"
#include "ShiftReg.h"
#include "ShiftDevice.h"
#include "Motor.h"
#include "Blinker.h"
// proxsensortest.ino

Proxsensor SensorMid(MID_ECHO_PIN,MID_TRIG_PIN,MAX_DIST);
Proxsensor SensorLeft(LEFT_ECHO_PIN,LEFT_TRIG_PIN,MAX_DIST);
Proxsensor SensorRight(RIGHT_ECHO_PIN,RIGHT_TRIG_PIN,MAX_DIST);
ShiftReg SRegister(DATA_PIN,LATCH_PIN,CLOCK_PIN);

void setup() {
Serial.begin(9600);
Serial.println("Start!");
}

void loop() {
SRegister.RedLED.on();
SRegister.GreenLED.on();
SRegister.LeftMotor.setPolarPWM(135);
SRegister.RightMotor.setPolarPWM(135);
SRegister.collectData();
SRegister.LeftMotor.run();
SRegister.RightMotor.run();
SRegister.shiftData();
delay(1000);


	// SRegister.setData(GREEN_LED_BIT);
	// SRegister.shiftData();
	// delay(1000);
	// SRegister.setData(RED_LED_BIT|GREEN_LED_BIT);
	// SRegister.shiftData();
	// delay(1000);
// int distM = SensorMid.calcObjDistance();
// int distL = SensorLeft.calcObjDistance();
// int distR = SensorRight.calcObjDistance();
// Serial.print(" Number of sensors: ");
// Serial.print(Proxsensor::getProxsensorcount());
// Serial.print("  L  ");
// Serial.print(distL);
// Serial.print("  M  ");
// Serial.print(distM);
// Serial.print("  R  ");
// Serial.println(distR);
// delay(50);



}

