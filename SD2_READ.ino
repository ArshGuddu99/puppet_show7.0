#include<SD.h>
#include<SPI.h>

#define no_of_74hc594 1
#define numOfRegisterPins no_of_74hc594 * 8
const int ser=5;
const int rclk=6;
const int srclk=7;

File myFile;

boolean registers[numOfRegisterPins];
int binarr[8];
byte binary;
int file_read;
int reading[10];
int read_value;
int rev_temp[8];
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


void loop() {
  // put your main code here, to run repeatedly:  
  if(myFile.available()){
    file_read=myFile.read()-'0';
    if(file_read<0)
      return;
  }
  else
    return;
  Serial.println(file_read);
  binary=0;
  dectobin();
  Serial.println(binary+1);
  for(int j=0;j<500;j++){
  digitalWrite(rclk, LOW);
  shiftOut(ser,srclk,MSBFIRST,(binary+1));
  digitalWrite(rclk, HIGH);
  delay(10);
}
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


