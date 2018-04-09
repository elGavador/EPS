#include <Wire.h>  // Library which contains functions to have I2C Communication
#define SLAVE_ADDRESS 8 // Define the I2C address to Communicate to Uno
#define LENGTH 1

byte response[LENGTH]; // this data is sent to PI
String data0;
uint8_t command[6]; //used to parse through the command packet
int d0, d1;   //data0 and data1
  
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS); // this will begin I2C Connection with 0x40 address
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.onReceive(receiveEvent);
  
  if (command[0] == 3)
  {  
    Serial.println(command[0]);
    Wire.onRequest(sendData); // sendData is funtion called when Pi requests data
  }
  delay(100);
  memset(command,0,sizeof(command));  //reset command
  delay(1000);
}
void sendData(){
  //byte bytes[8];
   response[0] = 0x20; //send back received data0
  
//  bytes[0] = myInt & 0xFF000000;
//  Serial.println(bytes[0]);
//  bytes[1] = (myInt >> 8) & 0x000000FF;
//  bytes[2] = (myInt >> 16) & 0x000000FF;
  
  Wire.write((byte *)response, LENGTH); // return data to PI
}

void receiveEvent(int howMany) {
  int i = 0;
  while(1 < Wire.available()) {
     command[i] = Wire.read();
     i++;
  }
  data0.concat(command[1]);
  data0.concat(command[2]);
  data0.concat(command[3]);
  data0.concat(command[4]);
  Serial.println(data0); 
  
}

//void write2LED(int pin)
//{
//  for (int i = 0; i<=10; i++)
//  {
//    Serial.println(pin);
//    digitalWrite(pin,HIGH);
//    delay(1000);
//    digitalWrite(pin, LOW);
//    delay(1000);
//  }
//}


