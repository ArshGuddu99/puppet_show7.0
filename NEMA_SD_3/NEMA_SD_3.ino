// defines pins numbers
#include<SD.h>
#include<SPI.h>
const int stepPin1 = 3; 
const int dirPin1 = 2;
const int stepPin2 =6;
const int dirPin2 = 5;
const int stepPin3= 8;
const int dirPin3=7;
int reading;
int file_read[6];
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
  if(!SD.begin(4)){
    Serial.println("Initialization failed");
    return;
  }
 Serial.println("Initialization successful");
 myFile=SD.open("motor1.txt",FILE_READ);
 if(!myFile){
  Serial.println("File opening failed");
  return;
 }
}

void zeros()
{for(int i=0;i<6;i++){
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
  while(j<=4){
    if(max_time<file_read[j])
    max_time=file_read[j];
    j+=2;
  }
}


void loop() {
  zeros();
  while(myFile.available()){
  for (int j=0;j<6;j++){
    arrtoint(j);
    Serial.println(file_read[j]);
  }
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,HIGH);
  digitalWrite(dirPin3,HIGH);
  maximum();
  for(int x=0;x<max_time;x++){
   if(x<file_read[0]){
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(file_read[1]);
    digitalWrite(stepPin1,LOW);
    delayMicroseconds(file_read[1]);
  }
   if(x<file_read[2]){
    digitalWrite(stepPin2,HIGH);
    delayMicroseconds(file_read[3]);
    digitalWrite(stepPin2,LOW);
    delayMicroseconds(file_read[3]);
  }
   if(x<file_read[4]){
    digitalWrite(stepPin3,HIGH);
    delayMicroseconds(file_read[5]);
    digitalWrite(stepPin3,LOW);
    delayMicroseconds(file_read[5]);
  } 

  }
}}
