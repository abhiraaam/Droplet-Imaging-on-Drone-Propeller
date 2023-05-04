#include <AFMotor.h>

AF_DCMotor motor(3);

void setup() {
}

void loop() {
  motor.setSpeed(250);
  motor.run(FORWARD);
}
