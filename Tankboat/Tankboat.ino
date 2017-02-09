int motorSpeed1 = 0;
int motorDirection1 = 1;
int motorSpeed2 = 0;
int motorDirection2 = 1;

   int directionPin1[] = {2,4};
 int speedPin1= 3;
 int directionPin2[] = {5,7};
 int speedPin2 = 6;
 
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

 pinMode(directionPin1[0], OUTPUT);
 pinMode(directionPin1[1], OUTPUT);
 pinMode(directionPin2[0], OUTPUT);
 pinMode(directionPin2[1], OUTPUT);
 pinMode(speedPin1, OUTPUT);
 pinMode(speedPin2, OUTPUT);


 digitalWrite(speedPin1, 0);
 digitalWrite(speedPin2,0);

 pinMode(1, INPUT);
 while(digitalRead(1) == 0){
     delay(1);
     }
 delay(3000);

}



 
void loop() {
  // put your main code here, to run repeatedly:
   motorDirection1=1;
motorDirection2=1;
  motorSpeed1=255;
 motorSpeed2=255;
 roboDrive();
 delay(1000);


// motorDirection1=1;
// motorDirection2=-1;
// motorSpeed1=255;
// motorSpeed2=0;
// roboDrive();
// delay(1000);
//
//
// motorDirection1=1;
// motorDirection2=1;
// motorSpeed1=255;
// motorSpeed2=255;
// roboDrive();
// delay(1000);
//
//
//
//  motorDirection1=-1;
// motorDirection2=1;
// motorSpeed1=0;
// motorSpeed2=255;
// roboDrive();
// delay(1000);
//
//  motorDirection1=-1;
// motorDirection2=-1;
// motorSpeed1=0;
// motorSpeed2=0;
// roboDrive();
// delay(1000);


}

 void roboDrive(){
Serial.print("motor 1: ");
Serial.print(motorDirection1);
Serial.print(" motor 2: ");
Serial.print(motorDirection2);

Serial.print(" motorSpeed1: ");
Serial.print(motorSpeed1);
Serial.print(" motorSpeed 2: ");
Serial.println(motorSpeed2);

 if(motorDirection1 == 1){ 
 digitalWrite(directionPin1[0], HIGH);
 digitalWrite(directionPin1[1], LOW);
 }
 else{
 digitalWrite(directionPin1[0], LOW);
 digitalWrite(directionPin1[1], HIGH);
 }
 if(motorDirection2 == 1){ //configure H bridge
 digitalWrite(directionPin2[0], HIGH);
 digitalWrite(directionPin2[1], LOW);
 }
 else{
 digitalWrite(directionPin2[0], LOW);
 digitalWrite(directionPin2[1], HIGH);
 }

 analogWrite(speedPin1, motorSpeed1);
 analogWrite(speedPin2, motorSpeed2);
 

 }
