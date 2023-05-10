#include <Servo.h>

Servo ESC;     // create servo object to control the ESC
Servo myservo;

int potValue;
int val;

void setup() {
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);
  ESC.attach(3,450,2000);
  myservo.attach(6);
  Serial.begin(9600);
}

void loop() {
  myservo.write(90);
  potValue = analogRead(A2);
  potValue = map(potValue, 0, 1020, 0, 180);
  val = analogRead(A0);
  val = map(val,0,1023,0,170);
  ESC.write(potValue);
  myservo.write(val);
  Serial.println(A2);
}
