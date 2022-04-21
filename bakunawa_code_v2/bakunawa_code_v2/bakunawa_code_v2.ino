//servo stuff
#include<VarSpeedServo.h>;
VarSpeedServo dragonServo;
VarSpeedServo moonServo;

//pins
const int pot1 = 1;
const int pot2 = 2;
const int pot3 = 3;
const int pot4 = 4;
//const int dragonServo = 5;
//const int moonServo = 6;
const int piezo1 = 7;
const int piezo2 = 8;
const int moonLight = 9;
const int startButton = 10; 
//more ints
int beginDiorama = 0;
int pot1State = 0;
int pot2State = 0;
int pot3State = 0;
int pot4State = 0;

void setup() {
 pinMode (pot1, INPUT);
 pinMode (pot2, INPUT);
 pinMode (pot3, INPUT);
 pinMode (pot4, INPUT);
 dragonServo.attach(5, 0, 180);
 moonServo.attach(6, 0, 180);
 //pinMode (dragonServo, OUTPUT); ignore these
 //pinMode (moonServo, OUTPUT);
 pinMode (piezo1, OUTPUT);
 pinMode (piezo2, OUTPUT);
 pinMode (moonLight, OUTPUT);
 pinMode (startButton, INPUT);
 Serial.begin(9600);
 dragonServo.write(0);
 moonServo.write(0);
}

void loop() {
  beginDiorama = digitalRead(startButton);
  pot1State = digitalRead(pot1);
  pot2State = digitalRead(pot2);
  pot3State = digitalRead(pot3);
  pot4State = digitalRead(pot4);
  if(beginDiorama == HIGH) {     //start
    Serial.println("ON");    //on test
    moonServo.write(90, 1);  //moon moves
    if(pot1State == HIGH && pot2State == HIGH && pot3State == HIGH && pot4State == HIGH) {
      dragonServo.detach(); //dragon stops
      moonServo.detach(); //moon stays
      Serial.println("THEY'RE ALL ON!!! WOOOOOOOOOO!!!!");
    }
    else { //bit scuffed, it doesn't loop between going left and going right 
      dragonServo.write(180, 10); //dragon keeps going
      dragonServo.wait();
      dragonServo.write(0, 10);
    }
    if(pot1State == HIGH || pot2State == HIGH || pot3State == HIGH || pot4State == HIGH) {
      Serial.println("at least one of 'ems on");
      dragonServo.write(20, 30); //extra wiggles?
    }
    //individual pot tests
    if(pot1State == HIGH) {
      Serial.println("pot 1 is on");
    }
    if(pot2State == HIGH) {
      Serial.println("pot 2 is on");
    }
    if(pot3State == HIGH) {
      Serial.println("pot 3 is on");
    }
    if(pot4State == HIGH) {
      Serial.println("pot 4 is on");
    }
  }
  if(beginDiorama = LOW) {  //supposed to be the reset but the dial doesn't "work" (like it turns on, but doesnt stay on) unless you weigh it down a bit
   moonServo.write(0);
   dragonServo.write(0);
  }
}
