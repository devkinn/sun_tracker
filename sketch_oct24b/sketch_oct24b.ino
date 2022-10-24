//#include<Servo.h>
#include<Arduino.h>
#include<ServoEasing.hpp>

ServoEasing servo1;

const int readPin = A0;
const int writePin = 9;

float curLightValue;
float prevLightValue;

bool positionSet;
float rotOffset = 15;

void setup() {
  Serial.begin(9600);
  servo1.attach(writePin, 0);

  prevLightValue = analogRead(readPin);
  prevLightValue = map(prevLightValue, 0, 1023, 0, 180);

  delay(1000);
}

void loop() {
  positionSet = false;
  curLightValue = analogRead(readPin);

  float voltage = curLightValue * (3.3 / 1023.0);
  //Serial.println(voltage);

  curLightValue = map(curLightValue, 0 , 1023, 0, 180);

  Serial.println(abs(curLightValue - prevLightValue));

  if(abs(curLightValue - prevLightValue) > rotOffset){
    prevLightValue = analogRead(readPin);
    prevLightValue = map(prevLightValue, 0, 1023, 0, 180);
    servo1.easeTo(curLightValue, 30);
    delay(500);
  }
}