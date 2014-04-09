#include "Arduino.h"
#include "Panel.h"
#include "InstrumentValues.h"

Panel::Panel(){
	//intialize the board with no values
	int numValues = 64;
	int muxValues[] = {
	  NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
	  NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
	  NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
	  NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
	  NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
	  NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,
	  NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE
	}

	//Mux control
	byte controlPins[] = {
	  B00000000, 
	  B10000000,
	  B01000000,
	  B11000000,
	  B00100000,
	  B10100000,
	  B01100000,
	  B11100000,
	  B00010000,
	  B10010000,
	  B01010000,
	  B11010000,
	  B00110000,
	  B10110000,
	  B01110000,
	  B11110000 };
	
}


