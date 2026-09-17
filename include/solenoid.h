#ifndef SOLENOID_H
#define SOLENOID_H

#include <Arduino.h>

#define SOLENOID_PIN 6

void solenoidInit();
void solenoidOn();
void solenoidOff();

#endif