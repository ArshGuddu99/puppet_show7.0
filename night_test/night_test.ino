// defines pins numbers
#include<SD.h>
#include<SPI.h>
#include<AccelStepper.h>
/*
Arduino MEGA 
MOSI -51
MISO - 50
SCK - 52
CS - 53 
*/

const int a_1= A3;
const int a_2= A2;
const int a_3= A1;
const int a_4= A0;
const int b_1= 8;
const int b_2= 7;
const int b_3= 6;
const int b_4= 5;

int pos= 1200;

 AccelStepper a(AccelStepper::FULL4WIRE, a_1,a_2,a_3,a_4);
 AccelStepper b(AccelStepper::FULL4WIRE, b_1,b_2,b_3,b_4);
 
void setup() {

  pinMode(a_1,OUTPUT); 
  pinMode(a_2,OUTPUT);
  pinMode(a_3,OUTPUT);
  pinMode(a_4,OUTPUT);
  pinMode(b_1,OUTPUT);
  pinMode(b_2,OUTPUT);
  pinMode(b_3,OUTPUT);
  pinMode(b_4,OUTPUT);

  // Sets the four pins corresponding to each driver as Outputs
  Serial.begin(9600); //begin serial communication

 //initialize the stepper motors using the library


 //set a maximum speed for each of these motors, for a start
 a.setMaxSpeed(400);
 b.setMaxSpeed(400);

 //initialize the stepper motors, all to a common acceleration
 a.setAcceleration(200);
 b.setAcceleration(200);

}


void loop() {
  
if(!a.distanceToGo() && !b.distanceToGo()){
  pos*=-1;
  //set the target position for each of the motors
  a.move(pos);
  b.move(pos);
 }

  //give the run command
  a.run();
  b.run();
  
  //delay(1000);
}
