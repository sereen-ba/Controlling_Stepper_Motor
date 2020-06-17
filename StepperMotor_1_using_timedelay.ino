#include <Stepper.h>
#define STEP_PER_MOTOR_REV 32
#define STEP_PER_OUY_REV 32*64
Stepper stepper(STEP_PER_MOTOR_REV,8,10,9,11);
int Steps2Take;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  Steps2Take = STEP_PER_OUY_REV;
  stepper.setSpeed(700);
  stepper.step(Steps2Take);
  delay(1000);

  Steps2Take = - STEP_PER_OUY_REV;
  stepper.setSpeed(500);
  stepper.step(Steps2Take);
  delay(1000);

}
