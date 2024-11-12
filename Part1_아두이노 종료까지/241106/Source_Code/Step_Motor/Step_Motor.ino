#include <Stepper.h>
int stepRevol = 2048;
Stepper myStepper(stepRevol, 8, 9, 10, 11);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(10);
}

void loop() {
  myStepper.step(stepRevol);
  delay(500);

  myStepper.step(stepRevol);
  delay(500);
}
