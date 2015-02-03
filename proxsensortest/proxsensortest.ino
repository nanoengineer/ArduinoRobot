
#include "Proxsensor.h"
#include "Blinker.h"
#include "ShiftReg.h"
// proxsensortest.ino

Proxsensor SensorMid(12,13,MAX_DIST);
Proxsensor SensorLeft(8,10,MAX_DIST);
Proxsensor SensorRight(9,11,MAX_DIST);
ShiftReg SRegister(DATA_PIN,LATCH_PIN,CLOCK_PIN);

void setup() {
Serial.begin(9600);
}

void loop() {
	SRegister.setData(GREEN_LED_BIT);
	SRegister.shiftData();
	delay(100);
	SRegister.setData(RED_LED_BIT);
	SRegister.shiftData();
	delay(100);
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

