#include <ArduinoRobot.h> 

void setup(){
  Robot.begin(); // initialize the library
  Robot.beginSpeaker();
  Robot.beginTFT();
}

void loop(){

  //Print
  Robot.debugPrint(111);

  //Get inpout
  int button = BUTTON_NONE;
  while(button==BUTTON_NONE) {
    button = Robot.keyboardRead();
  }
  Robot.beep(BEEP_SIMPLE);

  //Raise the shirt
  delay(14000);
  Robot.motorsWrite(0,255);
  delay(12000);
  Robot.motorsWrite(0,0);

  int pos;
  if( button == BUTTON_DOWN){
    pos = 3;
  } 
  else if( button == BUTTON_RIGHT){
    pos = 2;
  } 
  else{
    pos = 1;
  }

  //Print out the positon
  Robot.debugPrint(pos);

  //Go there
  rotateToPos(pos, -255);

  //Dump the shirt
  Robot.motorsWrite(0,255);
  delay(4000);

  //Go back
  rotateToPos(pos,255);

  //Lower the tray
  Robot.motorsWrite(0,-255);
  delay(7500);

  //Stop everything
  Robot.motorsWrite(0,0);
}

void rotateToPos(double spot, int power) {
  Robot.motorsWrite(power,0);
  delay(spot*1000);
  Robot.motorsWrite(0,0);
}







