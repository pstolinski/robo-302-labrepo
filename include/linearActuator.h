#ifndef LINEARACTUATOR_H
#define LINEARACTUATOR_H

#include <Arduino.h>

#define SDA_PIN 8
#define SCL_PIN 9
#define JRK_ADDRESS 11

// 30mm stroke = 0-4095
#define RETRACT_TARGET 566
#define EXTEND_TARGET 3296

void linearActuatorInit();
void linearActuator(int target);

#endif