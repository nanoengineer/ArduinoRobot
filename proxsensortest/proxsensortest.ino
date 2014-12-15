
#include "Proxsensor.h"
// proxsensortest.ino

Proxsensor pSensor1(11,12,70);

void setup() {
}

void loop() {
pSensor1.getDistance();
}

