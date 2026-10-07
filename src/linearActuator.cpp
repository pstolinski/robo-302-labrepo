#include "linearActuator.h"
#include <Wire.h>
#include <JrkG2.h>

JrkG2I2C jrk(JRK_ADDRESS);

void linearActuatorInit() {
	Wire.begin(SDA_PIN, SCL_PIN);
}

void linearActuator(int target) {
	jrk.setTarget(target);

	// stop once we're close to the target so it doesn't hunt
	unsigned long start = millis();
	while (abs(jrk.getScaledFeedback() - target) > POSITION_TOLERANCE && millis() - start < MOVE_TIMEOUT) {
		delay(10);
	}
	jrk.stopMotor();
}
