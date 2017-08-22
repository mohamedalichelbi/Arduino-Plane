/*
* Arduino Wireless Communication Tutorial
*     Example 2 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
int value = 0; // set values you need to zero
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#define button 4
RF24 radio(7, 8); // CNS, CE
const byte addresses[][6] = {"00001", "00002"};
Servo myServo;
Servo myServo1;
Servo firstESC;
boolean buttonState = 0;
void setup() {
  pinMode(button, INPUT);
  myServo.attach(5);
  myServo1.attach(6);
  firstESC.attach(9);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00002
  radio.openReadingPipe(1, addresses[1]); // 00001
  radio.setPALevel(RF24_PA_MIN);
  Serial.begin(115200);
}
void loop() {
  delay(5);
  radio.startListening();
  if ( radio.available()) {
    while (radio.available()) {
      int angleV = 0;
      int angleVTRUE = 0;
      radio.read(&angleV, sizeof(angleV));
      if (angleV < 180 )
             {
             angleVTRUE = angleV;
             }
      myServo.write(angleVTRUE);
         int angleV1 = 0;
         int angleV1TRUE = 0;
         radio.read(&angleV1, sizeof(angleV1));
         if (angleV1 < 180 )
              {
              angleV1TRUE = angleV1;
              }
         myServo1.write(angleV1TRUE);
             int angleV2 = 0;
             int angleV2TRUE = 0;
             radio.read(&angleV2, sizeof(angleV2));
             bitSet(angleV2, 0);
             if (angleV2 < 2100 &&   angleV2 > 700)
             {
             angleV2TRUE = angleV2;
             }
              angleV2TRUE = constrain(angleV2TRUE,700 , 2100);
                   
             firstESC.writeMicroseconds(angleV2TRUE);
               if(Serial.available()) 
               value = Serial.parseInt(); 
               Serial.println(angleV2TRUE);
    }
  }
}
