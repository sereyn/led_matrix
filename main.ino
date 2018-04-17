#include "myLeds.h"

Pad newlc = Pad(12, 10, 11, 4);

void setup(){
	newlc.initScreen(5);
}

void loop(){
	float index = 0;
	while(true){
		newlc.clear();
		for(int x=0; x<32; x++){
			newlc.setLed(x, cos(x+index)+5, true);
		}
		delay(5);
		index += 0.5;
	}
}