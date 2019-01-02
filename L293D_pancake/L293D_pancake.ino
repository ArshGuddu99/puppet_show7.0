#include<Stepper.h>

const int m_pin1=8;
const int m_pin2=9;
const int m_pin3=12;
const int m_pin4=13;

/*const int n_pin1=3;
const int n_pin2=4;
const int n_pin3=5;
const int n_pin4=6;*/

Stepper myStepper1= Stepper(200,m_pin1,m_pin2,m_pin3,m_pin4);
/*Stepper myStepper2=Stepper(200,n_pin1,n_pin2,n_pin3,n_pin4);*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   myStepper1.setSpeed(60);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("START");                                                                                                                 
  myStepper1.step(80);
  //myStepper2.setSpeed(100);
  //myStepper2.step(80);
  Serial.println("END");
  
}
