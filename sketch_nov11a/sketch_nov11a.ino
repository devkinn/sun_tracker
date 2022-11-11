#include <Arduino.h>
#include <Servo.h>

Servo servoY;
Servo servoX;
// gora prawo lewo dol
//
int topLDR = A0;
int rightLDR = A1;
int leftLDR = A2;
int botLDR = A3;

int topRead = 0;
int rightRead = 0;
int leftRead = 0;
int botRead = 0;

int thresholdValue = 10;

void setup(){
  Serial.begin(9600);

  servoY.attach(9);
  servoX.attach(10);

  servoY.write(0);
  delay(500);
  servoX.write(0);
  delay(500);
}

void loop(){
  topRead = analogRead(topLDR);
  rightRead = analogRead(rightLDR);
  leftRead = analogRead(leftLDR);
  botRead = analogRead(botLDR);

  int diffY = rightRead - leftRead;
  int diffX = topRead - botRead;

  Serial.print("Top Read: ");
  Serial.println(topRead * 5.0/1023);
  Serial.print("Right Read: ");
  Serial.println(rightRead * 5.0/1023);
  Serial.print("Left Read: ");
  Serial.println(leftRead * 5.0/1023);
  Serial.print("Bot Read: ");
  Serial.println(botRead * 5.0/1023);
  delay(1000);

  /*Serial.println("Diff Y:");
  Serial.println(diffY);
  Serial.println("Diff X:");
  Serial.println(diffX);
  */

  if(abs(diffY) >= thresholdValue){
    if(diffY > 0){
      if(servoY.read() < 180){
        servoY.write(servoY.read() + 2);
      }
    }

    if(diffY < 0){
      if(servoY.read() > 0){
        servoY.write(servoY.read() - 2);
      }
    }
  }

  if(abs(diffX) >= thresholdValue){
    if(diffX > 0){
      if(servoX.read() < 180){
        servoX.write(servoX.read() - 2);
      }
    }

    if(diffX < 0){
      if(servoX.read() > 0){
        servoX.write(servoX.read() + 2);
      }
    }
  }

}
