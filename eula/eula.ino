/* AET BAKUNAWA
 *  Team Name: Bakunawa Babies
 *  Team Members: Anna Roberts and Eula Tomamao
 *  Desc: Servo dragon tries to eat the moon but (hopefully) fails
 */

//servo library
#include<Servo.h>;

//variables
Servo myServo
const int buttonPin = 7;

void setup() {
  // put your setup code here, to run once:
 myServo.attach(9);
 pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //if button is pressed, swivel servo 180 degrees
 if(digitalRead(buttonPin) == HIGH) {
  mySevro.write(180);
 } else
 myServo.write(0);
 }
 //TODO: Add LED
}
