// defines pins numbers
#include<SD.h>
#include<SPI.h>
const int stepPin = 3; 
const int dirPin = 4; 
int reading;
int file_read_1;
int file_read_2;
int file_read;
File myFile;
 
void setup() {
  // Sets the two pins as Outputs// defines pins numbers
#include<SD.h>
#include<SPI.h>
const int stepPin = 3; 
const int dirPin = 4; 
int reading;
int file_read_1;
  Serial.begin(9600);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  if(!SD.begin(53)){
    Serial.println("Initialization failed");
    return;
  }
 Serial.println("Initialization successful");
 myFile=SD.open("data.txt",FILE_READ);
 if(!myFile){
  Serial.println("File opening failed");
  return;
 }
}


void arrtoint_1(){
  file_read_1=0;
  while((reading=myFile.read()-'0')!='\n')
    { if(reading!='\n'&&reading>=0)
        file_read_1=10*file_read_1+reading;
       else
        break;
    }
}

void arrtoint_2(){
  file_read_2=0;
  while((reading=myFile.read()-'0')!='\n')
    { if(reading!='\n'&&reading>=0)
        file_read_2=10*file_read_2+reading;
       else
        break;
    }
}
    
void loop() {
  while(myFile.available()){
  arrtoint_1();
  arrtoint_2();
  Serial.println(file_read_1);
  Serial.println(file_read_2);
  digitalWrite(dirPin,HIGH);
  for(int x=0;x<file_read_1;x++){
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(file_read_2);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(file_read_2);
  }
  delay(500);
  
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }
  delay(1000);
  }
}
