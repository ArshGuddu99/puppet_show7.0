// defines pins numbers
#include<SD.h>
#include<SPI.h>
const int stepPin1 = 3; 
const int dirPin1 = 2;
const int stepPin2 =6;
const int dirPin2 = 5;
const int stepPin3= 8;
const int dirPin3=7;
const int stepPin4 =10;
const int dirPin4 = 9;
const int stepPin5= 12;
const int dirPin5=11;
/*int reading;
int file_read[6];
File myFile;
int max_time=0;*/

 
void setup() {
  // Sets the two pins as Outputs
  Serial.begin(9600);
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(stepPin2,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  pinMode(dirPin3,OUTPUT);
  pinMode(stepPin3,OUTPUT);
  pinMode(stepPin4,OUTPUT);
  pinMode(dirPin4,OUTPUT);
  pinMode(dirPin5,OUTPUT);
  pinMode(stepPin5,OUTPUT);
 /* if(!SD.begin(4)){
    Serial.println("Initialization failed");
    return;
  }
 Serial.println("Initialization successful");
 myFile=SD.open("data.txt",FILE_READ);
 if(!myFile){
  Serial.println("File opening failed");
  return;
 }*/
}

/*void zeros()
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

*/
void loop() {
  /*zeros();
  while(myFile.available()){
  for (int j=0;j<6;j++){
    arrtoint(j);
    Serial.println(file_read[j]);
  }*/
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,HIGH);
  digitalWrite(dirPin3,HIGH);
  digitalWrite(dirPin4,HIGH);
  digitalWrite(dirPin5,HIGH);
 // maximum();
  for(int x=0;x<1200;x++){
   //if(x<400){
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin1,LOW);
    delayMicroseconds(600);
  //}
  // if(x<600){
    digitalWrite(stepPin2,HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin2,LOW);
    delayMicroseconds(800);
 // }
   ///if(x<800){
    digitalWrite(stepPin3,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin3,LOW);
    delayMicroseconds(500);
  //} 
   //  if(x<1000){
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  //} 
    //   if(x<1200){
    digitalWrite(stepPin5,HIGH);
    delayMicroseconds(1500);
    digitalWrite(stepPin5,LOW);
    delayMicroseconds(1500);
  //} 

  }
}
