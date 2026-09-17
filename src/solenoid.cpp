#include "solenoid.h"

void solenoidInit() {
	pinMode(SOLENOID_PIN, OUTPUT);
	digitalWrite(SOLENOID_PIN, LOW);
}

void solenoidOn() {
	digitalWrite(SOLENOID_PIN, HIGH);
}

void solenoidOff() {
	digitalWrite(SOLENOID_PIN, LOW);
}