#include <Servo.h>

Servo ESC;     // create servo object to control the ESC
Servo myservo;

int potValue;  // value from the analog pin
int potpin = A0;
int val;

void setup() {
  pinMode(3,OUTPUT);
  // Attach the ESC on pin 9
  ESC.attach(3,1000,1001); // (pin, min pulse width, max pulse width in microseconds) 
  myservo.attach(6);
  Serial.begin(9600);
}

void loop() {
  myservo.write(90);
  potValue = analogRead(A2);   // reads the value of the potentiometer (value between 0 and 1023)
  potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  val = analogRead(potpin);
  val = map(val,0,1023,0,180);
  ESC.write(potValue);
  myservo.write(val);    // Send the signal to the ESC
  Serial.println(A2);
  delay(1);
}