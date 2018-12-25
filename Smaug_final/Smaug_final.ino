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
 
const int a_1= A4;
const int a_2= A3;
const int a_3= A2;
const int a_4= A1;
const int b_1= 10;
const int b_2= 9;
const int b_3= 8;
const int b_4= 7;
int j;
 AccelStepper a(AccelStepper::FULL4WIRE, a_1, a_2, a_3, a_4);
 AccelStepper b(AccelStepper::FULL4WIRE, b_1, b_2, b_3, b_4);

int reading;
int file_read[4];
File myFile;

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
  if(!SD.begin(4)){  //initialize the SD card for later use
    Serial.println("Initialization failed");
    return;
  }
 Serial.println("Initialization successful");
 myFile=SD.open("smaug.txt",FILE_READ);  //Open the required file from the SD card
 if(!myFile){   //Check if the file has opened properly
  Serial.println("File opening failed");
  return;
 }


 //set a maximum speed for each of these motors, for a start
 a.setMaxSpeed(200);
 b.setMaxSpeed(200);

 //initialize the stepper motors, all to a common acceleration
 a.setAcceleration(50);
 b.setAcceleration(50);

}

void zeros()  //make all values in array zero, to avoid junk errors
{for(int i=0;i<4;i++){
  file_read[i]=0;
}
}

void arrtoint(int i){   // convert the values read from the array in character form to integer
    file_read[i]=0;
   while((reading=myFile.read()-'0')!='\n')
    { if(reading!='\n'&&reading>=0)                          
        file_read[i]=10*file_read[i]+reading;
       else
        break;
    }
}

void loop() {
  if(a.distanceToGo()==0 && b.distanceToGo()==0){
  zeros();
  j=0;
  while(myFile.available()&& j<4){
  for (j=0;j<4;j++){
    arrtoint(j);
    Serial.println(file_read[j]);
  }}
  if(!myFile.available()){
    Serial.println("END");
  
  }
  //set the maximum speeds for each of the motors as read from the file
  if(file_read[0]!=12345){
  a.setMaxSpeed(file_read[1]);
  b.setMaxSpeed(file_read[3]);

  //set the target position for each of the motors
  a.move(file_read[0]);
  b.move(file_read[2]);

  Serial.println("motor 1:Max Speed:");
  Serial.print(file_read[1]);
  Serial.println("motor 1: Target pos: ");
  Serial.print(file_read[0]);
  Serial.println("motor 2: Max Speed: ");
  Serial.print(file_read[3]);
  Serial.println("motor 2:  Target pos: ");

  }}

  if(file_read[0]!=12345){
  //give the run command
  a.run();
  b.run();
 }

  else
    delay(file_read[1]);
}
