#ifndef MYLEDS
#define MYLEDS

#include "LedControl.h"

class Pad{
private:
	int DIN;
	int CLK;
	int CS;
	int length;
	LedControl lc = LedControl(0, 0, 0, 0);
public:
	Pad(int DIN, int CLK, int CS, int length);
	void initScreen(int intensity);
	void setLed(int x, int y, bool value);
	void clear();
};

#endif //MYLEDS
