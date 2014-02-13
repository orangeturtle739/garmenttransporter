#include <Servo.h>
Servo servo1;
void setup(){
  Serial.begin(9600);
  servo1.attach(11);
  
}
void loop(){
  delay(900);
  servo1.write(0);
  Serial.println(0);
  delay(2000);
  servo1.write(120);
  Serial.println(120);
  delay(2000);
  servo1.write(120+30);
  Serial.println(120+30);
  delay(2000);
  servo1.write(2);
  Serial.println(2);
}
