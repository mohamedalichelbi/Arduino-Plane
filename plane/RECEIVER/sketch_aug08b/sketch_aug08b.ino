/*
* Arduino Wireless Communication Tutorial
*     Example 2 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
struct dataStruct{
  int angleV;
  int angleV1;
  int angleV2;
}myData1;

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
  firstESC.attach(3);
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
      radio.read(&myData1, sizeof(myData1));
     //myData1.angleV    //these elements now contain received data*
     //myData1.angleV1*
     //myData1.angleV2*
      
      int angleV = 0;
      

     angleV = myData1.angleV;  //so move elemtes to local variables*
      //angleV1= myData1.angleV1; //added*
      //angleV1= myData1.angleV1; //added*
     //comments, I would make send receive tyme names same myData both
//txrx*
      //also do not need angle V variables as i believe you can use
//directly myData1.angleV instead of angleV etc*
      //hope this helps, PeterSek*

     
      myServo.write( myData1.angleV);
      int angleV1 = 0;
      
      angleV1= myData1.angleV1; //added...**//also do not need angle V
//variables as i believe you can use directly myData1.angleV instead of
//angleV etc*

     
      myServo1.write( myData1.angleV1);
      int angleV2 =  0;
      
     angleV1= myData1.angleV1; //added...**//also do not need angle V
//variables as i believe you can use directly myData1.angleV instead of
//angleV etc*

      

                   
             firstESC.writeMicroseconds( myData1.angleV2);
               if(Serial.available()) 
               value = Serial.parseInt(); 
               Serial.println( myData1.angleV);
               Serial.println( myData1.angleV1);
               Serial.println( myData1.angleV2);
    }
  }
}
