#include <Stepper.h>
#define STEP_PER_MOTOR_REV 32
#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8
#define joyStick A0
Stepper stepper(STEP_PER_MOTOR_REV,IN4,IN2,IN3,IN1);


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int val = analogRead(joyStick);
  if((val >500) && (val <700))
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    
  }
  else{
    while(val >= 700)
    {
      int speed_=map(val,700,1023,5,500);
      stepper.setSpeed(speed_);
      stepper.step(1);
       val = analogRead(joyStick);
    }
    while(val<=500)
    {
      int speed_=map(val,500,0,5,500);
      stepper.setSpeed(speed_);
      stepper.step(-1);
       val = analogRead(joyStick);
      
    }
  }

}
