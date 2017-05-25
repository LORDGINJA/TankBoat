#include <Servo.h>
Servo myServo;
Servo myservo;

int angle = 0;
int Angle = 0;
int angleDelta = 5;
long spinTime = 0;
const int servoPin = 6; 
const int servopin = 7;
int ch3=10;
int ch4=9;

void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(servopin, OUTPUT);
  myServo.attach(servoPin);
myservo.attach(servopin);
 pinMode(ch3, INPUT);
  pinMode(ch4, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  ch3 = pulseIn(10, HIGH, 25000);
  delay(50);
  ch4 = pulseIn(9, HIGH, 25000);

 if(ch3 < 1300){    
  servoTurn2R();
 }
 else if(ch3 > 1700){
  servoTurn2L();
 }
 if(ch4 < 1400){
  servoTurn1R();
 }
 else if(ch4 > 1600){
  servoTurn1L();
 }

 Serial.print("Channel 3:");
 Serial.print(ch3);
 Serial.print("\t");
 Serial.print("Channel 4:");
 Serial.println(ch4); // for new line
 Serial.print("\t");
// Serial.print("Angle: ");
// Serial.println(Angle); // for new line
// Serial.print("\t");
// Serial.print("angle: ");
// Serial.println(angle); // for new line
// Serial.print("\t");
// 
}

void servoTurn1L(){
  Serial.print("1L ");
//  if(Angle < 70){
Angle+=angleDelta;
//}
myServo.write(Angle);
delay(10);
}

void servoTurn2L(){
  Serial.print("2L ");
//  if(angle < 70){
  angle+=angleDelta;
//  }
myservo.write(angle);
delay(10);
}

void servoTurn1R(){
  Serial.print("1R ");
  Angle-=angleDelta;
myServo.write(Angle);
delay(10);
}

void servoTurn2R(){
  Serial.print("2R ");
  angle-=angleDelta;
myservo.write(angle);
delay(10);
}


