#include "myLeds.h"

Pad myPads[] = {Pad(13, 9, 6, 4),Pad(5, 4, 3, 4) , Pad(12, 11, 10, 4)};
Screen myScreen = Screen(myPads, 3);

void setup(){
	myScreen.init(5);
}

void loop(){
  for(int x=0; x<32; x++){
    /*int y1 = cos(x/2)*10+10;
    int y2 = cos((x+1)/2)*10+10;
    int y1 = (x-16)/2*(x-16)/2;
    int y2 = (x-15)/2*(x-15)/2;*/
    if(x != 0 && (x+1) != 0){
      int y1 = 1/x;
      int y2 = 1/(x+1);
      myScreen.line(x, y1, x+1, y2); 
    }
  }
	
}
