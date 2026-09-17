#include <Arduino.h>
#include "stepper.h"
#include "solenoid.h"

void setup() {
  stepperInit();
  solenoidInit();
}

boolean isSolenoidOn = false;

void loop() {
  //stepperCW(200);
  //stepperCCW(200);

  while(!isSolenoidOn){
  for(int i = 0; i < 3; i++) {
    solenoidOn();
    delay(500);
    solenoidOff();
    delay(500);
  }
  isSolenoidOn = true;
}
  



  //increases step speed conservatively
  // for(int delayTime = 2500; delayTime >= 250; delayTime -= 250) {
  //   digitalWrite(DIR_PIN, HIGH);
  //   for (int i = 0; i < 200; i++) {
  //     digitalWrite(STEP_PIN, HIGH);
  //     delayMicroseconds(delayTime);
  //     digitalWrite(STEP_PIN, LOW);
  //     delayMicroseconds(delayTime);
  //   }
  //   delay(500); 
  //   digitalWrite(DIR_PIN, LOW);
  //   for (int i = 0; i < 200; i++) {
  //     digitalWrite(STEP_PIN, HIGH);
  //     delayMicroseconds(delayTime);
  //     digitalWrite(STEP_PIN, LOW);
  //     delayMicroseconds(delayTime);
  //   }
  //   delay(500); 
  // }

}