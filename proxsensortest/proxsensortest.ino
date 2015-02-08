#include "SonarRobot.h"

// proxsensortest.ino
SonarRobot myRobot;

void setup() {
Serial.begin(9600);
}

void loop() {
myRobot.sensorgroupPing();
myRobot.calcMotorDrives();
myRobot.activate();
// delay(10);

// myRobot.GreenLED.on();
// myRobot.RedLED.off();
// myRobot.activate();

// myRobot.sensorgroupPing();

// int distM = myRobot.SensorMid.calcObjDistance();
// int distL = myRobot.SensorLeft.calcObjDistance();
// int distR = myRobot.SensorRight.calcObjDistance();

// Serial.print("  L  ");
// Serial.print(distL);
// Serial.print("  M  ");
// Serial.print(distM);
// Serial.print("  R  ");
// Serial.println(distR);
}

