//code to control rotation of stepper motor with different speeds for different times
#include <Stepper.h>
const int in_1=8;
const int in_2=9;
const int in_3=10;
const int in_4=11;

const int no_of_steps=200;

Stepper myStep= Stepper(no_of_steps,in_1,in_2,in_3,in_4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println("Start");
    myStep.setSpeed(60);
    Serial.println("60 rpm");
    myStep.step(80);
    myStep.setSpeed(100);
    Serial.println("100 rpm");
    myStep.step(120);
    Serial.println("Backwards");
    myStep.step(-200);
  
}
