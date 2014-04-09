#ifndef Panel_h
#define Panel_h

include "Arduino.h"
include "instrumentValues.h"
include <Wire.h>

class Panel
{
public:
	Panel();
	void valueScan();

private:
	int numValues;
	int muxValues[64];
	int controlPins[16];
	int inputPins[4];
	//functions
	void setPin(int _pin);
	int smooth(int _pin);
	


}