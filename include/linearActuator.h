#ifndef LINEARACTUATOR_H
#define LINEARACTUATOR_H

#include <Arduino.h>

#define SDA_PIN 8
#define SCL_PIN 9
#define JRK_ADDRESS 11

#define RETRACT_TARGET 200
#define EXTEND_TARGET 3200

#define POSITION_TOLERANCE 40
#define MOVE_TIMEOUT 5000

void linearActuatorInit();
void linearActuator(int target);

#endif
