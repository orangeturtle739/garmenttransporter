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
  servo1.write(60);
  Serial.println(60);
  delay(2000);
  servo1.write(60-20);
  Serial.println(60-20);
  delay(2000);
  servo1.write(155);
  Serial.println(155);
}
