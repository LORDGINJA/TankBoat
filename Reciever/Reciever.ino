int ch1=8;
int ch2=9;
int ch3=10;

 int motorSpeed1 = 0;
int motorDirection1 = 1;
int motorSpeed2 = 0;
int motorDirection2 = 1;

   int directionPin1[] = {2,4};
 int speedPin1= 3;
 int directionPin2[] = {5,7};
 int speedPin2 = 6;
 
 void setup() {
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
pinMode(ch1, INPUT); // Set our input and output pins as such
 pinMode(ch2, INPUT);
 pinMode(ch3, INPUT);
 pinMode(led, OUTPUT);
 Serial.begin(9600); //initialise serial
 
}
 
void loop() {
 
ch1 = pulseIn(8, HIGH, 25000); // Read the HIGH pulse width of
 ch2 = pulseIn(9, HIGH, 25000); // each channel with timeout specified
 ch3 = pulseIn(10, HIGH, 25000);
 
Serial.print("Channel 1:"); // Printing the value of
 Serial.print(ch1); // each channel
 Serial.print("\t");
 Serial.print("Channel 2:");
 Serial.print(ch2);
 Serial.print("\t");
 Serial.print("Channel 3:");
 Serial.println(ch3); // for new line
 
if(ch1 < 1400){
  motorDirection1=1;
motorDirection2=-1;
  motorSpeed1=255;
 motorSpeed2=255;
 Serial.print("Left");
 roboDrive();
 delay(1000);
}

if(ch1 > 1700){     //right
 motorDirection1=-1;
 motorDirection2=1;
 motorSpeed1=255;
 motorSpeed2=255;
 Serial.print("Right");
 roboDrive();
 delay(1000);
}

if(ch2 < 1400){     //backwards
 motorDirection1=-1;
 motorDirection2=-1;
 motorSpeed1=255;
 motorSpeed2=255;
 Serial.print("backwards");
 roboDrive();
 delay(1000);
}

if(ch2 > 1600){    //forward
  motorDirection1=1;
 motorDirection2=1;
 motorSpeed1=255;
 motorSpeed2=255;
 Serial.print("forwards");
 roboDrive();
 delay(1000);
}
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
