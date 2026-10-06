#include "linearActuator.h"
#include <Wire.h>
#include <JrkG2.h>

JrkG2I2C jrk(JRK_ADDRESS);

void linearActuatorInit() {
	Wire.begin(SDA_PIN, SCL_PIN);

	// check that the Jrk answers on the I2C bus
	Wire.beginTransmission(JRK_ADDRESS);
	if (Wire.endTransmission() == 0) {
		Serial.printf("Jrk found at I2C address %d\n", JRK_ADDRESS);
	} else {
		Serial.printf("Jrk NOT found at I2C address %d - check wiring, pull-ups, GND, device number\n", JRK_ADDRESS);

		// scan the whole bus to see if anything answers
		int found = 0;
		for (uint8_t address = 1; address < 127; address++) {
			Wire.beginTransmission(address);
			if (Wire.endTransmission() == 0) {
				Serial.printf("  device found at I2C address %d\n", address);
				found++;
			}
		}
		if (found == 0) {
			Serial.println("  no I2C devices found on the bus");
		}
	}
}

void linearActuator(int target) {
	jrk.setTarget(target);
	uint8_t i2cError = jrk.getLastError();

	uint16_t feedback = jrk.getFeedback();
	uint16_t errorFlags = jrk.getErrorFlagsHalting();

	// i2cErr 0 = command delivered, errFlags 0 = Jrk is allowed to drive the motor
	Serial.printf("target=%d feedback=%u i2cErr=%u errFlags=0x%04X\n",
		target, feedback, i2cError, errorFlags);
}
