
#include "Proxsensor.h"
// proxsensortest.ino

Proxsensor SensorMid(12,13,700);
Proxsensor SensorLeft(8,10,700);
Proxsensor SensorRight(9,11,700);

void setup() {
Serial.begin(9600);
}

void loop() {
int distM = SensorMid.calcObjDistance();
int distL = SensorLeft.calcObjDistance();
int distR = SensorRight.calcObjDistance();
Serial.print(" Number of sensors: ");
Serial.print(Proxsensor::getProxsensorcount());
Serial.print("  L  ");
Serial.print(distL);
Serial.print("  M  ");
Serial.print(distM);
Serial.print("  R  ");
Serial.println(distR);
delay(50);
}

