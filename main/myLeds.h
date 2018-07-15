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

class Screen{
private:
	Pad pads[] = {};
	int nbPads;
public:
	Screen(Pad pads[], int length);
	void init(int intensity);
	void setLed(int x, int y, bool value);
	void line(int x1, int y1, int x2, int y2);
};

int sign(float x);

#endif //MYLEDS
