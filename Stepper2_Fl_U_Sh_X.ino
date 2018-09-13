int ser = 7; //datapin
int rclk=6; //latchpin
int srclk=5; //clockpin
int j=0;
#define number_of_74hc595s 1

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];

void clearRegisters(){
  for(int i = 7; i >=  0; i--){
     registers[i] = LOW;
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(ser,OUTPUT);
  pinMode(rclk,OUTPUT);
  pinMode(srclk,OUTPUT);
  clearRegisters();

}

void loop() {
  // put your main code here, to run repeatedly://500 means <90 degrees
for(j=0;j<500;j++){
digitalWrite(rclk, LOW);
  shiftOut(ser,srclk,MSBFIRST,B00000011);
  digitalWrite(rclk, HIGH);
delay(1);
digitalWrite(rclk, LOW);
  shiftOut(ser,srclk,MSBFIRST,B00000000);
  digitalWrite(rclk, HIGH);
  delay(1);
}
for(j=0;j<500;j++){
digitalWrite(rclk, LOW);
  shiftOut(ser,srclk,MSBFIRST,B00001111);
  digitalWrite(rclk, HIGH);
delay(1);
digitalWrite(rclk, LOW);
  shiftOut(ser,srclk,MSBFIRST,B00001100);
  digitalWrite(rclk, HIGH);
  delay(1);
}

}
