#include <Servo.h>
//Define servo and switch ports.
#define servo1_port 3
#define servo2_port 5
#define servo3_port 6
#define switch_port 2
//Define the zero positions for the servos.
#define servo1_inital_position 155
#define servo2_inital_position 50
#define servo3_inital_position 2
//Define the 90 degree position for the servos.
#define servo1_90_position 60
#define servo2_90_position 130
#define servo3_90_position 120
//Define the number which needs to be added to the 90 degree value in order the reach the final location.
#define servo1_90_to_final -20
#define servo2_90_to_final 20
#define servo3_90_to_final 30
//Calculate the final positions of all the servos.
#define servo1_final_position servo1_90_to_final + servo1_90_position
#define servo2_final_position servo2_90_to_final + servo2_90_position
#define servo3_final_position servo3_90_to_final + servo3_90_position
//Define all other constants
#define delay_after_movement 1500
Servo servo1;
Servo servo2;
Servo servo3;
void setup(){
  pinMode(switch_port,INPUT);
  servo1.attach(servo1_port);
  servo2.attach(servo2_port);
  servo3.attach(servo3_port);
  relaxServos();
  
  //Serial.begin(9600);
  //Serial.println(digitalRead(switch_port));
  if(digitalRead(switch_port)==HIGH){
    while(digitalRead(switch_port)==HIGH);
    delay(200);
  }else if(digitalRead(switch_port)==LOW){
    while(digitalRead(switch_port)==LOW);
    delay(200);
    while(digitalRead(switch_port)==HIGH);
    delay(200);
  }
  resetServos(true);
  
}
void loop(){
  
  if(digitalRead(switch_port)==HIGH){
    
    sendServoToPosition(1,servo1_final_position,true);
    sendServoToPosition(1,servo1_inital_position,false);
    sendServoToPosition(3,servo3_final_position,true);
    sendServoToPosition(3,servo3_inital_position,false);
    sendServoToPosition(1,servo1_final_position,true);
    sendServoToPosition(1,servo1_inital_position,false);
    if(digitalRead(switch_port)==LOW){
      sendServoToPosition(3,servo3_final_position,true);
      sendServoToPosition(3,servo3_inital_position,false);
      while(digitalRead(switch_port)==LOW);
    }
    delay(100);
    sendServoToPosition(2,servo2_final_position,true);
    sendServoToPosition(2,servo2_inital_position,true);
    while(digitalRead(switch_port)==HIGH);
    delay(50);
    sendServoToPosition(2,servo2_final_position,true);
    sendServoToPosition(2,servo2_inital_position,true);
    relaxServos();
 }
  
}
void resetServos(boolean wait){
  servo1.write(servo1_inital_position);
  servo2.write(servo2_inital_position);
  servo3.write(servo3_inital_position);
  if(wait){
    delay(delay_after_movement);
    relaxServos();
  }
}
void relaxServos(){
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}
void sendServoToPosition(int servoNum, int servoPosition, boolean wait){
  switch(servoNum){
    case 1:
      servo1.write(servoPosition);
      break;
    case 2:
      servo2.write(servoPosition);
      break;
    case 3:
      servo3.write(servoPosition);
      break;
  }
  if(wait)
    delay(delay_after_movement);
}
