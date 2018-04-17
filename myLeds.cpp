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

