#include<SD.h>
#include<SPI.h>

#define no_of_74hc594 1
#define numOfRegisterPins no_of_74hc594 * 8
/*const int ser=5;
const int rclk=6;
const int srclk=7;*/

boolean registers[numOfRegisterPins];
byte binarr[8];
byte binary;
int file_read;
byte rev_temp[8];
int i,j;

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
 /* pinMode(ser,OUTPUT);
  pinMode(rclk,OUTPUT);
  pinMode(srclk,OUTPUT);
  clearRegisters();*/

}

void loop() {
  // put your main code here, to run repeatedly:
  File myFile=SD.open("data.txt",FILE_READ);
  
  file_read=myFile.read();
  Serial.println(file_read);
  binary=0;
  dectobin();
  Serial.println(binary);
  /*for(int j=0;j<500;j++){
  digitalWrite(rclk, LOW);
  shiftOut(ser,srclk,MSBFIRST,binary);
  digitalWrite(rclk, HIGH);
  delay(1);
}*/
}

void dectobin()
{ 
  for(i=0;i<8;i++)
    binarr[i]=0;  
    i=0;
   while(file_read/2!=0){
    binarr[i]=file_read%2;
    file_read/=2;
    i++;
   }
   reverse();
   for(i=0;i<8;i++)
    binary+=binarr[i]*pow(10,7-i);
}

void reverse()
{for(j=0;j<8;j++)
  rev_temp[j]=binarr[7-j];
 for(j=0;j<8;j++)
  binarr[j]=rev_temp[j];
}
