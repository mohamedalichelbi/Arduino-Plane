/*
* Arduino Wireless Communication Tutorial
*     Example 2 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
struct dataStruct{
  int angleValue;
  int angleValue1;
  int angleValue2;
}myData;

int value = 0; // set values you need to zero
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define led 12
RF24 radio(7, 8); // CNS, CE
const byte addresses[][6] = {"00001", "00002"};
boolean buttonState = 0;
    #define MAX_SIGNAL 2100
    #define MIN_SIGNAL 700
void setup() {
  pinMode(12, OUTPUT);
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00001
  radio.openReadingPipe(1, addresses[0]); // 00002
  radio.setPALevel(RF24_PA_MIN);
  Serial.begin(115200); 
}
void loop() {
  delay(5);
  radio.stopListening();
  int potValue = analogRead(A0);
  int angleValue = map(potValue, 0, 1023, 0, 180);
  
      int potValue1 = analogRead(A1);
      int angleValue1 = map(potValue1, 0, 1023, 0, 180);
      
          int potValue2 = analogRead(A2);
          int angleValue2 = map(potValue2, 0, 1023, MIN_SIGNAL, MAX_SIGNAL);
myData.angleValue = angleValue;     //add these 3 lines*
myData.angleValue1 = angleValue1;   //add these 3 lines*
myData.angleValue2 = angleValue2;   //add these 3 lines*
  radio.write(&myData, sizeof(myData));
                 radio.write(&myData, sizeof(myData));

                 
           if(Serial.available()) 
           value = Serial.parseInt();    // Parse an Integer from Serial
           Serial.println(myData.angleValue);
           Serial.println(myData.angleValue1);
           Serial.println(myData.angleValue2);
}
