//2 buttons control a servo left and right
//1 button to "fire" an LED
//Poteniometer to control fire speed

#include <Servo.h>

Servo servo;
int angle = 70; //angle of the servo
//int pot = A0;
//int potValue = 0;
int leftBtn = 7;
int rightBtn = 6;
int leftBtnState = LOW;
int rightBtnState = LOW;

void setup() {
  servo.attach(9); // the servo is attached to pin 9 output
  //pinMode(pot, INPUT);
  pinMode(leftBtn, INPUT);
  pinMode(rightBtn, INPUT);
    Serial.begin(9600); //sets baud rate

}




void loop(){
  leftBtnState = digitalRead(leftBtn);
  rightBtnState = digitalRead(rightBtn);
  
  //if left button down and right button up go left -1
  if(leftBtnState == HIGH && rightBtnState == LOW){
   angle--;
    servo.write(angle);
  }
  //if right btn down and left button down go right +1
    if(leftBtnState == LOW && rightBtnState == HIGH){
    angle++;
    servo.write(angle);
  }
  //else nothing
  
 // servo.write(angle); //write to the angle (0 at the top)
  
  //delay(15);
  
    Serial.println(angle);

  
  
}
