#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CNS, CE
const byte addresses[][6] = {"00001", "00002", "00003"};
void setup() {
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00001
  radio.openWritingPipe(addresses[2]); // 00002
  radio.openWritingPipe(addresses[3]); // 00003
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(5);
  radio.stopListening();
  int potValue = analogRead(A0);
  int angleValue = map(potValue, 0, 1023, 0, 180);
  radio.write(&angleValue, sizeof(angleValue));
     int potValue1 = analogRead(A1);
     int angleValue1 = map(potValue1, 0, 1023, 0, 180);
     radio.write(&angleValue1, sizeof(angleValue1));
         int potValue2 = analogRead(A2);
         int angleValue2 = map(potValue2, 0, 1023, 0, 180);
         radio.write(&angleValue2, sizeof(angleValue2));
  delay(5);
}
