#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
RF24 radio(7, 8); // CNS, CE
const byte addresses[][6] = {"00001", "00002", "00003"};
Servo myServo;
void setup() {
  myServo.attach(3);
  myServo1.attach(5);
  myServo2.attach(6);
  radio.begin();
  radio.openReadingPipe(addresses[1]); // 00001
  radio.openReadingPipe(2, addresses[2]); // 00002
  radio.openReadingPipe(3, addresses[3]); // 00003
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(5);
  radio.startListening();
  if ( radio.available()) {
    while (radio.available()) {
      int angleV = 0;
      radio.read(&angleV, sizeof(angleV));
      myServo.write(angleV);
          int angleV1 = 0;
          radio.read(&angleV1, sizeof(angleV1));
          myServo.write(angleV1);
              int angleV2 = 0;
              radio.read(&angleV2, sizeof(angleV2));
              myServo.write(angleV2);
    }
  }
}
