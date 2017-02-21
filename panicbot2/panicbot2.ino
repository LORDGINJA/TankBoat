#include <Servo.h>
Servo myServo;
Servo myservo;

int angle = 0;
int angleDelta = 1;
long spinTime = 0;
const int servoPin = 9; 
const int servopin = 11;



void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(servopin, OUTPUT);
  myServo.attach(servoPin);
myservo.attach(servopin);
  Serial.begin(9600);
  
}

void loop() {
  
     servoTurn();


}

void servoTurn(){
myServo.write(angle);
myservo.write(angle);
delay(10);
if ( angle+angleDelta>180 || angle+angleDelta <=0 ){ 
    angleDelta *= -1;
    }
angle+=angleDelta;
}

