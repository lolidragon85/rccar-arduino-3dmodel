#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define buttonPin1 3

int buttonState1 = 0;
RF24 radio(8, 10);
const byte address[6] = "00002";
void setup() {
  pinMode(buttonPin1, INTPUT_PULLUP);
  Serial.begin();
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

}

void loop() {
  buttonState1 = digitalRead(buttonPin1);

  if (buttonState1 == 1)
  {
  
    buttonState1 = 1;    
  
  }  else if (buttonState1 == 0)        

    buttonState1 = 0
    
  }
}
