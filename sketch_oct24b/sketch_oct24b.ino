#include<Servo.h>

Servo servo1;

const int readPin = A0;
const int writePin = 9;

int lightCal;
int lightVal;

void setup() {
  Serial.begin(9600);
  servo1.attach(writePin);

  pinMode(writePin, OUTPUT);
  lightCal = analogRead(readPin);
}

void loop() {
  lightVal = analogRead(readPin);
  lightVal = map(lightVal, 0 , 1023, 0, 180);

  /*if(lightVal < lightCal - 50){
    digitalWrite(writePin, HIGH);
  }else{
    digitalWrite(writePin, LOW);
  }*/

  servo1.write(lightVal);

  float voltage = lightVal * (3.3 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);

  delay(15);
}