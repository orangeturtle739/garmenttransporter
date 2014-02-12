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
  servo1.write(130);
  Serial.println(130);
  delay(2000);
  servo1.write(130+20);
  Serial.println(120+20);
  delay(2000);
  servo1.write(50);
  Serial.println(50);
}
