#include "myLeds.h"

//PAD PUBLIC

Pad::Pad(int DIN, int CLK, int CS, int length){
	this-> DIN = DIN;
	this-> CLK = CLK;
	this-> CS = CS;
	this-> length = length;
	this->lc = LedControl(DIN, CLK, CS, length);
}

void Pad::initScreen(int intensity){
	int nb_devices = this->lc.getDeviceCount();
	for(int i=0; i<nb_devices; i++){
		this->lc.shutdown(i, false);
		this->lc.setIntensity(i, intensity);
		this->lc.clearDisplay(i);
	}
}

void Pad::setLed(int x, int y, bool value){
	int nb_devices = this->lc.getDeviceCount();
	this->lc.setLed(floor(x/8), y, 7-(x%8), value);
}

void Pad::clear(){
	int nb_devices = this->lc.getDeviceCount();
	for(int i=0; i<nb_devices; i++){
		this->lc.clearDisplay(i);
	}
}

//SCREEN PUBLIC

Screen::Screen(Pad pads[], int length){
	for(int i=0; i<length; i++){
		this->pads[i] = pads[i];
	}
	this->nbPads = length;
}

void Screen::init(int intensity){
	for(int i=0; i<this->nbPads; i++){
		this->pads[i].initScreen(intensity);
	}
}

void Screen::setLed(int x, int y, bool value){
	int padIndex = y/8;
	this->pads[padIndex].setLed(x, y%8, value);
}

void Screen::line(int x1, int y1, int x2, int y2){
	int dx = x2-x1;
	int dy = y2-y1;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float Xinc = dx/(float)steps;
	float Yinc = dy/(float)steps;
	float x = x1;
	float y = y1;
	for(int i=0; i<=steps; i++){
		this->setLed(x, y, true);
		x += Xinc;
		y += Yinc;
	}
}

//UTILS

int sign(float x){
	if(x<0.0){
		return -1;
	}else{
		return 1;
	}
}