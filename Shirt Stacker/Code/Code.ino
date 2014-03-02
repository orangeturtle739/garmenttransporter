#include <ArduinoRobot.h> 

void setup(){
  Robot.begin(); // initialize the library
  Robot.beginSpeaker();
}

void loop(){

  int button = BUTTON_NONE;
  while(button==BUTTON_NONE) {
    button = Robot.keyboardRead();
  }
  Robot.beep(BEEP_SIMPLE);

  delay(15000);
  Robot.motorsWrite(0,255);
  delay(10000);
  Robot.motorsWrite(0,0);

  if( button == BUTTON_DOWN){
    Robot.motorsWrite(255,0);
    delay(1000);
    Robot.motorsWrite(0,0);
  } 
  else if( button == BUTTON_RIGHT){
    Robot.motorsWrite(255,0);
    delay(2000);
    Robot.motorsWrite(0,0);
  } 
  else if( button == BUTTON_UP){
    Robot.motorsWrite(255,0);
    delay(3000);
    Robot.motorsWrite(0,0);
  }
  
  Robot.motorsWrite(0,0);
}
















