#include "myLeds.h"

Pad myPads[] = {Pad(13, 9, 6, 4),Pad(5, 4, 3, 4) , Pad(12, 11, 10, 4)};
Screen myScreen = Screen(myPads, 3);

void setup(){
	myScreen.init(5);
}

void loop(){
myScreen.setLed(12,6, true);myScreen.setLed(16,6, true);myScreen.setLed(12,7, true);myScreen.setLed(16,7, true);myScreen.setLed(12,8, true);myScreen.setLed(16,8, true);myScreen.setLed(12,9, true);myScreen.setLed(16,9, true);myScreen.setLed(12,10, true);myScreen.setLed(16,10, true);myScreen.setLed(8,13, true);myScreen.setLed(21,13, true);myScreen.setLed(8,14, true);myScreen.setLed(9,14, true);myScreen.setLed(20,14, true);myScreen.setLed(9,15, true);myScreen.setLed(10,15, true);myScreen.setLed(19,15, true);myScreen.setLed(20,15, true);myScreen.setLed(11,16, true);myScreen.setLed(12,16, true);myScreen.setLed(13,16, true);myScreen.setLed(17,16, true);myScreen.setLed(18,16, true);myScreen.setLed(19,16, true);myScreen.setLed(13,17, true);myScreen.setLed(14,17, true);myScreen.setLed(15,17, true);myScreen.setLed(16,17, true);myScreen.setLed(17,17, true);
}

