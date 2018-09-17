#include<SD.h>
#include<SPI.h>



#define no_of_74hc594 1
#define numOfRegisterPins no_of_74hc594 * 8
const int ser=7;
const int rclk=8;
const int srclk=9;
String data[9];

boolean registers[numOfRegisterPins];

void clearRegisters(){
  for(int i = 7; i >=  0; i--){
     registers[i] = LOW;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(!SD.begin(4)){
    Serial.println("INIT FAILED");
    return;
  }
  
  
  
  pinMode(ser,OUTPUT);
  pinMode(rclk,OUTPUT);
  pinMode(srclk,OUTPUT);
  clearRegisters();

}

void loop() {
  // put your main code here, to run repeatedly:
  File myFile=SD.open("data.txt",FILE_READ);
  for(int i=0;i<9;i++){
    data[i]=myFile.read();
  }
  for(int j=0;j<500;j++){
   digitalWrite(rclk, LOW);
  shiftOut(ser,srclk,MSBFIRST,data);
  digitalWrite(rclk, HIGH);
  delay(1);
}
}
