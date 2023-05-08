/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
Servo esc;
Servo servo;
RF24 radio(7, 8); // wifi modules pins(CE, CSN) are connected to pins (7, 8)
const byte addresses[][6] = {"node1", "node2"};
byte wewe;
struct MyData {
  int state1;
  int state2;
  int state3;
  int state4;
  };
  MyData data;
  int vel;

void resetData() 
{
  data.state1 = 0;
  data.state2 = 0;
  data.state3 = 0;
  data.state4 = 0;
}
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, addresses [0]);
  radio.setPALevel(RF24_PA_MIN);
  servo.attach(9); //command pin of the steering servo is connected to pin 9
  esc.attach(3); //Specify the esc signal pin,Here as 3
  esc.writeMicroseconds(1000); //initialize the signal to 1000

  
}
void loop() {
  //lettura segnale radio
  radio.startListening();
  if (radio.available()) {
  radio.read(&data, sizeof(MyData));
  }
  //motor speed control
  if (data.state1>710) vel=900;//710 you will have to change this value, based on your potentiometer signal
  if (data.state1<710 and data.state1>640) vel= 2000-(data.state1-640)*13;//710 and 640 you will have to change this values, based on your potentiometer signal
  if (data.state1<640) vel=2000;//640 you will have to change this value, based on your potentiometer signal
  esc.writeMicroseconds(vel);
  //steering servo control
  if (data.state2<460){ //460 you will have to change this value, based on your potentiometer signal
    wewe=107+(460-data.state2)/12; //107 is the 0 angle of my steering servo
  }
  if (data.state2>540){//540 you will have to change this value, based on your potentiometer signal
    wewe=107-(data.state2-540)/12;
  }
  if (data.state2>460 and data.state2<540) wewe=107;//460 and 540 you will have to change this values, based on your potentiometer signal
  
  Serial.println (vel);
  servo.write (wewe);
}
