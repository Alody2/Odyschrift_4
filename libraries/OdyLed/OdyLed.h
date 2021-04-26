 
/*
  OdyLed.h - Library for Ody input.
  Created by Alle van Meeteren, 27 april 2020. 
*/
#ifndef OdyLed_h
#define OdyLed_h
#define NUM_LEDS 12  // # of LEDS in the strip
CRGB leds[NUM_LEDS];
#define PIN 12 // ZIt op pin 12
#define COLOR_ORDER GRB  // I had to change this for my strip if your color is off then you know.

#include "Arduino.h"
#include "FastLED.h"
#include "OdyInput.h"

class OdyLed
{
	public:
		OdyLed(	
				int dirLeft,
				int dirRight,
				int dirUp,
				int dirDown,
				int numleds, //aantal ledjes,
				int pinled //pin waaraan de matrix ledjes is verbonden,	
			);
		OdyInput odyinput;
		
	private:
};
#endif

