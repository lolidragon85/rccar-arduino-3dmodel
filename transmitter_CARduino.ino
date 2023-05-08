/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // wifi module pins (CE, CSN) are connected to pins (7,8) of the arduino 
struct MyData {
 int state1;
  int state2;
  int state3;
  int state4;
};

MyData data;

void resetData() 
{
  data.state1 = 0;
  data.state2 = 0;
  data.state3 = 0;
  data.state4 = 0;
}
const byte address[6] = "node1";
void setup() {
  pinMode (A0, INPUT);// steering potentiometer output is connected to pin 5
  pinMode (A1, INPUT);// throttle potentiometer output is connected to pin 2
  pinMode (4, INPUT);// optional third input pin
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  
  Serial.begin (9600);
}
void loop() {
  radio.stopListening();
  data.state1= analogRead(A0); //send throttle data
  data.state2=analogRead(A1); //send steering data
  data.state3=analogRead(4); //optional third data
  Serial.println (data.state1);
  radio.write (&data,sizeof(MyData));
  delay(1);
}
