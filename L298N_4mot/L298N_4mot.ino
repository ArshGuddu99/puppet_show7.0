// defines pins numbers
#include<SD.h>
#include<SPI.h>
#include<Stepper.h>
/*
Arduino MEGA 
MOSI -51
MISO - 50
SCK - 52
CS - 53 
*/
const int a_1= 2;
const int a_2= 3;
const int a_3= 4;
const int a_4= 5;
const int b_1= A3;
const int b_2= A2;
const int b_3= A1;
const int b_4= A0;
const int c_1= 22;
const int c_2= 24;
const int c_3= 26;
const int c_4= 28;
const int d_1= 36;
const int d_2= 38;
const int d_3= 40;
const int d_4= 42;

int reading;
int file_read[8];
File myFile;
int max_time=0;
 
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
  if(!SD.begin(53)){  //initialize the SD card for later use
    Serial.println("Initialization failed");
    return;
  }
 Serial.println("Initialization successful");
 myFile=SD.open("Drum.txt",FILE_READ);  //Open the required file from the SD card
 if(!myFile){   //Check if the file has opened properly
  Serial.println("File opening failed");
  return;
 }
 //initialize the stepper motors using the library
 Stepper a(200, a_1,a_2,a_3,a_4);
 Stepper b(200, b_1,b_2,b_3,b_4);
 Stepper c(200, c_1, c_2, c_3, c_4);
 Stepper d(96, d_1, d_2, d_3, d_4);

 //set a maximum speed for each of these motors
 a.setMaxSpeed(200);
 b.setMaxSpeed(200);
 c.setMaxSpeed(200);
 d.setMaxSpeed(200);

 //initialize the stepper motors, all to a common acceleration
 a.setAcceleration(500);
 b.setAcceleration(500);
 c.setAcceleration(500);
 d.setAcceleration(500);

 
 
}

void zeros()  //make all values in array zero, to avoid junk errors
{for(int i=0;i<15;i++){
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

void maximum(){
  int j=0;
  while(j<=14){
    if(max_time<file_read[j])
    max_time=file_read[j];
    j+=3;
}}


void loop() {
  zeros();
  while(myFile.available()){
  for (int j=0;j<8;j++){
    arrtoint(j);
    Serial.println(file_read[j]);
  }
  a.move(file_read[0]);
  b.move(file_read[2]);
  c.move(file_read[4]);
  d.move(file_read[6]);
  a.run();
  b.run();
  c.run();
  d.run();
//delay(1000);
}}
