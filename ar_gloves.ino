#include <Servo.h>
String str;
int servo1Pin = 9;
int servo2Pin = 10;
Servo Servo1;
Servo Servo2;
void setup() {

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Servo1.attach(servo1Pin);
  Servo2.attach(servo2Pin);
  pinMode(servo1Pin,INPUT);
  pinMode(servo2Pin,INPUT);
  Servo1.write(0);
  Servo2.write(0);
  Serial.begin(9600);
}
void loop(){

if(Serial.available() > 0)
{
    str=Serial.readString();
   if(str == "grab")
   {
     pinMode(servo1Pin,OUTPUT);
     pinMode(servo2Pin,OUTPUT);
     Serial.println(str);
     digitalWrite(2, LOW);
     digitalWrite(4, LOW);
     digitalWrite(3, HIGH);
     digitalWrite(5, HIGH);
     delay(35);
     digitalWrite(3, LOW);
     digitalWrite(5, LOW);
     delay(35);
     //delay(100);
     Servo1.write(180);
     Servo2.write(180);
     delay(800);
     pinMode(servo1Pin,INPUT);
     pinMode(servo2Pin, INPUT);
   }
   else if(str == "drop")
   {
      pinMode(servo1Pin,OUTPUT);
     pinMode(servo2Pin,OUTPUT);
     Serial.println(str);
     Servo1.write(0);
     Servo2.write(0);
     delay(800);
     pinMode(servo1Pin,INPUT);
     pinMode(servo2Pin, INPUT);
   }
   else if(str == "push")
   {
     Serial.println(str);

     digitalWrite(2, LOW);
     digitalWrite(4, LOW);
     digitalWrite(3, HIGH);
     digitalWrite(5, HIGH);
     delay(35);
     digitalWrite(3, LOW);
     digitalWrite(5, LOW);
     delay(35);
   }
   else
   { while(str == "rain")
     {
       delay(1000);
       digitalWrite(2, LOW);
       digitalWrite(4, LOW);
       digitalWrite(3, HIGH);
       digitalWrite(5, HIGH);
       delay(35);
       digitalWrite(3, LOW);
       digitalWrite(5, LOW);
       delay(35);
     }
   }
 }
