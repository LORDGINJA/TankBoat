#include <Servo.h>
Servo myServo;
Servo myservo;

int angle = 45;
int Angle = 45;
int angleDelta = 5;
long spinTime = 0;
const int servoPin = 6; 
const int servopin = 7;
int ch3=10;
int ch5=11;

void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(servopin, OUTPUT);
  myServo.attach(servoPin);
myservo.attach(servopin);
 pinMode(ch3, INPUT);
  pinMode(ch5, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  ch3 = pulseIn(10, HIGH, 25000);
  ch5 = pulseIn(11, HIGH, 25000);

 if(ch3 < 1300){    
  servoTurn1L();
   delay(250);
 }
 else if(ch3 > 1700){
  servoTurn1R();
   delay(250);
 }
 else if(ch5 < 1400){
  servoTurn2L();
   delay(250);
 }
 else if(ch5 > 1600){
  servoTurn2R();
   delay(250);
 }

 Serial.print("Channel 3:");
 Serial.print(ch3);
 Serial.print("\t");
 Serial.print("Channel 4:");
 Serial.println(ch5); // for new line
 Serial.print("\t");
}

void servoTurn1L(){
  Serial.print("1L ");
  if(Angle < 70){
Angle+=angleDelta;}
myServo.write(Angle);
delay(10);
//if ( Angle+angleDelta>180 || Angle+angleDelta <=0 ){ 
//    angleDelta *= -1;
//    }
}

void servoTurn2L(){
  if(Angle > 15){
Angle-=angleDelta;}
  Serial.print("2L ");
myServo.write(Angle);
delay(10);
//if ( angle+angleDelta>180 || angle+angleDelta <=0 ){ 
//    angleDelta *= -1;
//    }
}

void servoTurn1R(){
  Serial.print("1R ");
myServo.write(Angle);
delay(10);
//if ( Angle+angleDelta>180 || Angle+angleDelta <=0 ){ 
//    angleDelta *= -1;
//    }
Angle-=angleDelta;
}

void servoTurn2R(){
  Serial.print("2R ");
myservo.write(angle);
delay(10);
//if ( angle+angleDelta>180 || angle+angleDelta <=0 ){ 
//    angleDelta *= -1;
//    }
angle-=angleDelta;
}


