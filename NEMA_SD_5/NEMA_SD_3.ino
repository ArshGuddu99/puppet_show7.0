// defines pins numbers
#include<SD.h>
#include<SPI.h>
const int stepPin1 = 2; 
const int dirPin1 = 3;
const int stepPin2 =4;
const int dirPin2 = 5;
const int stepPin3= 6;
const int dirPin3=7;
const int stepPin4=10;
const int dirPin4=11;
const int stepPin5=12;
const int dirPin5=13;
int reading;
int file_read[15];
File myFile;
int max_time=0;
 
void setup() {
  // Sets the two pins as Outputs
  Serial.begin(9600);
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(stepPin2,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  pinMode(dirPin3,OUTPUT);
  pinMode(stepPin3,OUTPUT);
  pinMode(dirPin4,OUTPUT);
  pinMode(stepPin4,OUTPUT);
  pinMode(dirPin5,OUTPUT);
  pinMode(stepPin5,OUTPUT);
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

void zeros()
{for(int i=0;i<15;i++){
  file_read[i]=0;
}
}

void arrtoint(int i){
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
  for (int j=0;j<15;j++){
    arrtoint(j);
    Serial.println(file_read[j]);
  }
  digitalWrite(dirPin1,file_read[2]);
  digitalWrite(dirPin2,file_read[5]);
  digitalWrite(dirPin3,file_read[8]);
  digitalWrite(dirPin4,file_read[11]);
  digitalWrite(dirPin5,file_read[14]);
  maximum();
  for(int x=0;x<max_time;x++){
   if(x<file_read[0]){
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(file_read[1]);
    digitalWrite(stepPin1,LOW);
    delayMicroseconds(file_read[1]);
  }
   if(x<file_read[3]){
    digitalWrite(stepPin2,HIGH);
    delayMicroseconds(file_read[4]);
    digitalWrite(stepPin2,LOW);
    delayMicroseconds(file_read[4]);
  }
   if(x<file_read[6]){
    digitalWrite(stepPin3,HIGH);
    delayMicroseconds(file_read[7]);
    digitalWrite(stepPin3,LOW);
    delayMicroseconds(file_read[7]);
  } 
   if(x<file_read[9]){
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(file_read[10]);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(file_read[10]);
  } 
     if(x<file_read[12]){
    digitalWrite(stepPin5,HIGH);
    delayMicroseconds(file_read[13]);
    digitalWrite(stepPin5,LOW);
    delayMicroseconds(file_read[13]);
  } 
  }
}}
