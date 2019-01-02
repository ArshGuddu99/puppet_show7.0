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

const int a_1= A8;
const int a_2= A9;
const int a_3= A10;
const int a_4= A11;
const int b_1= 10;
const int b_2= 11;
const int b_3= 12;
const int b_4= 13;
const int e_1= A0;
const int e_2= A1;
const int e_3= A2;
const int e_4= A3;
const int c_1= 2;
const int c_2= 3;
const int c_3= 4;
const int c_4= 5;
const int d_1= 6;
const int d_2= 7;
const int d_3= 8;
const int d_4= 9;
const int f_1= A4;
const int f_2= A5;
const int f_3= A6;
const int f_4= A7;

int pos= 2400;

 AccelStepper a(AccelStepper::FULL4WIRE, a_1,a_2,a_3,a_4);
 AccelStepper b(AccelStepper::FULL4WIRE, b_1,b_2,b_3,b_4);
 AccelStepper c(AccelStepper::FULL4WIRE, c_1,c_2,c_3,c_4);
 AccelStepper d(AccelStepper::FULL4WIRE, d_1,d_2,d_3,d_4);
 AccelStepper e(AccelStepper::FULL4WIRE, e_1,e_2, e_3,e_4);
 AccelStepper f(AccelStepper::FULL4WIRE, f_1,f_2,f_3,f_4);
 
void setup() {
  a.disableOutputs();
  b.disableOutputs();
  c.disableOutputs();
  d.disableOutputs();
  e.disableOutputs();
  f.disableOutputs();
  // Sets the four pins corresponding to each driver as Outputs
  a.enableOutputs();
  a.setAcceleration(50);
  a.setMaxSpeed(500);
  a.move(-2400);
  while(a.distanceToGo()){
    a.run();
  }
a.move(400);
a.setAcceleration(50);
while(a.distanceToGo()){
  a.run();
}
a.disableOutputs();
delay(12500);
b.enableOutputs();
b.setAcceleration(50);
b.setMaxSpeed(500);
b.move(-2400);
while(b.distanceToGo()){
  b.run();
}
b.disableOutputs();
delay(4000);
a.enableOutputs();
a.setAcceleration(22);
a.move(-100);
while(a.distanceToGo()){
  a.run();
}
a.disableOutputs();
delay(17000);
b.enableOutputs();
b.setAcceleration(200);
b.move(2400);
while(b.distanceToGo()){
  b.run();
}
b.disableOutputs();
a.enableOutputs();
a.setAcceleration(152);
a.move(1900);
while(a.distanceToGo()){
  a.run();
}
a.disableOutputs();
delay(6000);  //joey's scene ends
delay(5000);  //sherlock's scene starts 
delay(2500);  //sherlock starts entering 
c.enableOutputs();
c.move(2400);
c.setAcceleration(50); 
c.setMaxSpeed(500);
while(c.distanceToGo()){
  c.run();
}
c.disableOutputs();
delay(200);
c.enableOutputs();
c.move(-600);
while(c.distanceToGo()){
 c.run(); 
}
c.disableOutputs();
delay(200);
c.enableOutputs();
c.move (600);
while(c.distanceToGo()){
  c.run();
}
c.disableOutputs();
delay(1000);
b.enableOutputs();
b.move(-2400);
while(b.distanceToGo()){
  b.run();
}
b.disableOutputs();
delay(3000);  //i need a case
delay(11000); //genie's dialogue
b.enableOutputs();
b.move(2400);
while(b.distanceToGo()){
  b.run();
}
b.disableOutputs();
delay(2000); //gap before do you miss me starts
c.enableOutputs();
c.move(-600);
while(c.distanceToGo()){
  c.run();
}
c.move(600);
while(c.distanceToGo()){
  c.run();
}
c.move(-2400);
while(c.distanceToGo()){
  c.run();
}
c.disableOutputs();
delay(8000);  //gap before tyrion starts entering
d.enableOutputs();
d.setAcceleration(50);
d.setMaxSpeed(500);
d.move(-2000);
while(d.distanceToGo()){
  d.run();
}
d.disableOutputs();
delay(6000); // lamp and smoke precursor to genie is shown
b.enableOutputs();
b.move(-2400);  
while(b.distanceToGo()){
  b.run();
}b.disableOutputs();             // genie enters, takes 5 secs
delay(2000);  // your wish is my command
delay(3000);  // genie moves his hands 
b.enableOutputs();
b.move(2400);
while(b.distanceToGo()){
  b.run();
}b.disableOutputs();             
//genie exits 5 secs
delay(3000);
  e.enableOutputs();
  e.setAcceleration(50);
  e.setMaxSpeed(500);
  e.move(2400);
  while(e.distanceToGo()){
    e.run();
  }           // dragon enters from the right 10 secs
  e.disableOutputs();
  delay(5000); //gap before dragon theme ends
  d.enableOutputs();
  d.move(-500);
 while(d.distanceToGo()){
  d.run();
 }d.disableOutputs();            //tyrion moves closer to the dragon, 2900 steps from zero
  delay(1000); // tyrion commands dragon
  delay(4000); // dragon flaps wings twice
  d.enableOutputs();
  d.setAcceleration(150);
  d.move(2600);
  while(d.distanceToGo()){
    d.run();  //tyrion moves away from the dragon, now 300 steps away from zero
  }d.disableOutputs();
  delay(2200);  // spear appears from the left and hits the dragon
  delay(7000);  // The hurt dragon drops its wings, and lays still
  f.enableOutputs();
  f.setMaxSpeed(500);
  f.setAcceleration(50);
  f.move(2400); 
  while(f.distanceToGo()){
    f.run();
  }f.disableOutputs();             // Night king moves in to the scene
  delay(7000); // dragon breathes blue fire on tyrion...  
  d.enableOutputs();
  f.enableOutputs();
  d.setAcceleration(50);
  d.setMaxSpeed(500);
  d.move(300);
  f.move(-1200);
  while(d.distanceToGo() || f.distanceToGo()){
    d.run();
    f.run(); 
  } d.disableOutputs();
  f.disableOutputs();// tyrion exits the scene and night king moves away from the dragon, and lowers his arm
  delay(16000); // two seconds after exiting the screen, night king raises hand and holds it for 1.5 seconds, and dragon blows the wall,
  f.enableOutputs();
  f.setAcceleration(50);
  f.setMaxSpeed(500);
  f.move(-1200);
  e.enableOutputs();
  e.setAcceleration(50);
  e.setMaxSpeed(500);
  e.move(-1200);
  while(e.distanceToGo() || f.distanceToGo()){
    e.run();
    f.run();
  }           // all characters exit the screen
  e.disableOutputs();
  f.disableOutputs();
}
void loop() {
  }


