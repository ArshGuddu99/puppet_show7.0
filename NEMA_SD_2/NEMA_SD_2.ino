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

 
void setup() {
  // Sets the two pins as Outputs
  Serial.begin(9600);
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(stepPin2,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  if(!SD.begin(4)){
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
{for(int i=0;i<6;i++){
  file_read[i]=0;
}
}

void arrtoint(int i){
  file_read[i]=0;
  Serial.println(file_read[i]);
  while((reading=myFile.read()-'0')!='\n')
    { if(reading!='\n'&&reading>=0)
        file_read[i]=10*file_read[i]+reading;
       else
        break;
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
  for(int x=0;x<file_read[0];x++){
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(file_read[1]);
    digitalWrite(stepPin1,LOW);
    delayMicroseconds(file_read[1]);
  }
  delay(500);
  digitalWrite(dirPin2,HIGH); 
   for(int x=0;x<file_read[2];x++){
    digitalWrite(stepPin2,HIGH);
    delayMicroseconds(file_read[3]);
    digitalWrite(stepPin2,LOW);
    delayMicroseconds(file_read[3]);
  }
  delay(500);
    digitalWrite(dirPin3,HIGH); 
   for(int x=0;x<file_read[4];x++){
    digitalWrite(stepPin3,HIGH);
    delayMicroseconds(file_read[5]);
    digitalWrite(stepPin3,LOW);
    delayMicroseconds(file_read[5]);
  } 
  delay(500);

  }
}
