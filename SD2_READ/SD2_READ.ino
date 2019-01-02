#include<SD.h>
#include<SPI.h>
#define no_of_74hc594 1
#define numOfRegisterPins no_of_74hc594 * 8
const int ser=7;
const int rclk=6;
const int srclk=5;

boolean registers[numOfRegisterPins];

File myFile;

int binarr[8];
uint8_t binary;
int file_read;
int reading;
int i,j;
void clearRegisters(){
  for(int i = 7; i >=  0; i--){
     registers[i] = LOW;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");
  if(!SD.begin(4)){
    Serial.println("INIT FAILED");
    delay(3000);
    exit(0);
  }
  Serial.println("INIT Successful");
  myFile=SD.open("data.txt",FILE_READ);
  pinMode(ser,OUTPUT);
  pinMode(rclk,OUTPUT);
  pinMode(srclk,OUTPUT);
  clearRegisters();
}

void arrtoint(){
  file_read=0;
  while(myFile.available())
    {reading=myFile.read()-'0';
      if(reading!='\n'&&reading>=0)
        file_read=10*file_read+reading;
       else
        break;
    }

}



void loop() {
  // put your main code here, to run repeatedly: 
 if(myFile.available()){ 
  arrtoint();
  Serial.println(file_read);
  binary=0;
  dectobin();
  Serial.println(binary);
for(j=0;j<500;j++){
digitalWrite(rclk, LOW);
  shiftOut(ser,srclk,MSBFIRST,binary);
  digitalWrite(rclk, HIGH);
delay(1);
  if(binary/1000==0)
{digitalWrite(rclk, LOW);
  shiftOut(ser,srclk,MSBFIRST,B00000000);
  digitalWrite(rclk, HIGH);
delay(1);}
  if(binary/1000==1)
  {digitalWrite(rclk, LOW);
  shiftOut(ser,srclk,MSBFIRST,B00001100);
  digitalWrite(rclk, HIGH);
delay(1);}
  

}}
  else
   { 
     Serial.println("Nothing to read");
     exit(0);}
}

void dectobin()
{
  Serial.print("In the decimal to binary function now, obtained value is: ");
  Serial.println(file_read); 
  Serial.print("of size: ");
  Serial.println(sizeof(file_read));
  for(i=0;i<8;i++)
    binarr[i]=0;  
   i=0;
   while((file_read/2!=0)||(file_read==1)){
    binarr[i]=file_read%2;
    file_read=file_read/2;
    i++;
   }
   //reverse();
   for(i=0;i<8;i++)
    binary+=binarr[i]*pow(10,i);
}

/*void reverse()
{for(j=0;j<8;j++)
  rev_temp[j]=binarr[7-j];
 for(j=0;j<8;j++)
  binarr[j]=rev_temp[j];
}*/


