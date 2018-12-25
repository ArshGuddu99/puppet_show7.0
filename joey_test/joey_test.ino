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

const int a_1= A1;
const int a_2= A2;
const int a_3= A3;
const int a_4= A4;
const int b_1= A8;
const int b_2= A9;
const int b_3= A10;
const int b_4= A11;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
const int c_1= 4;
const int c_2= 5;
const int c_3= 6;
const int c_4= 7;
const int d_1= 8;
const int d_2= 9;
const int d_3= 10;
const int d_4= 11;

int pos= -1200;

//int reading;
//int file_read[8];
//File myFile;
//int max_time=0;

 AccelStepper a(AccelStepper::FULL4WIRE, a_1,a_2,a_3,a_4);
 AccelStepper b(AccelStepper::FULL4WIRE, b_1,b_2,b_3,b_4);
 AccelStepper c(AccelStepper::FULL4WIRE, c_1, c_2, c_3, c_4);
 AccelStepper d(AccelStepper::FULL4WIRE, d_1, d_2, d_3, d_4);

void setup() {
  pinMode(a_1,OUTPUT); 
  pinMode(a_2,OUTPUT);
  pinMode(a_3,OUTPUT);
  pinMode(a_4,OUTPUT);
  pinMode(b_1,OUTPUT);
  pinMode(b_2,OUTPUT);
  pinMode(b_3,OUTPUT);
  pinMode(b_4,OUTPUT);
  pinMode(c_1,OUTPUT);
  pinMode(c_2,OUTPUT);
  pinMode(c_3,OUTPUT);
  pinMode(c_4,OUTPUT);
  pinMode(d_1,OUTPUT);
  pinMode(d_2,OUTPUT);
  pinMode(d_3,OUTPUT);
  pinMode(d_4,OUTPUT);
  // Sets the four pins corresponding to each driver as Outputs
  Serial.begin(9600); //begin serial communication
  /*if(!SD.begin(53)){  //initialize the SD card for later use
   * 
    Serial.println("Initialization failed");
    return;
  }
 Serial.println("Initialization successful");
 myFile=SD.open("Drum.txt",FILE_READ);  //Open the required file from the SD card
 if(!myFile){   //Check if the file has opened properly
  Serial.println("File opening failed");
  return;
 }*/
 //initialize the stepper motors using the library


 //set a maximum speed for each of these motors, for a start
 a.setMaxSpeed(200);
 b.setMaxSpeed(200);
 c.setMaxSpeed(200);
 d.setMaxSpeed(200);

 //initialize the stepper motors, all to a common acceleration
 a.setAcceleration(100);
 b.setAcceleration(100);
 c.setAcceleration(100);
 d.setAcceleration(100);
}

/*void zeros()  //make all values in array zero, to avoid junk errors
{for(int i=0;i<8;i++){
  file_read[i]=0;
}
}*/

/*void arrtoint(int i){   // conve AccelStepper c(AccelStepper::FULL4WIRE, c_1, c_2, c_3, c_4);
 AccelStepper d(AccelStepper::FULL4WIRE, d_1, d_2, d_3, d_4);rt the values read from the array in character form to integer
  file_read[i]=0;
  while((reading=myFile.read()-'0')!='\n')
    { if(reading!='\n'&&reading>=0)                          
        file_read[i]=10*file_read[i]+reading;
       else
        break;
    }
}*/

void loop() {
  //zeros();
  /*while(myFile.available()){
  for (int j=0;j<8;j++){
    arrtoint(j);
    Serial.println(file_read[j]);
  }*/
  //set the maximum speeds for each of the motors as read from the file
if(!a.distanceToGo() && !b.distanceToGo() && !c.distanceToGo() && !d.distanceToGo()){
  pos*=-1;
  //set the target position for each of the motors
  a.move(pos);
  b.move(pos);
  c.move(pos);
  d.move(pos);}

  //give the run command
  a.run();
  b.run();
  c.run();
  d.run();
  
  //delay(1000);
}
