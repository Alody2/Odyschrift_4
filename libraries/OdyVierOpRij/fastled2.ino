/* 
#include "FastLED.h"
#define NUM_LEDS 12  // # of LEDS in the strip
CRGB leds[NUM_LEDS];
#define PIN 12 // ZIt op pin 12
#define COLOR_ORDER GRB  // I had to change this for my strip if your color is off then you know.
int fadeAmount = 25;  // Set the amount to fade I usually do 5, 10, 15, 20, 25 etc even up to 255.
int brightness = 0; 
//---------------------------------------------------------------------------

void setup() {
  /* 
  put your setup code here, to run once. Below, the joystick related pins are defined as 
  digital inputs (reading on or off)
  */
FastLED.addLeds<WS2812B, PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //setup voor de LED strip
  // this code below is a little colour freestyle for no real specific use. It just shows a few colours on the board LED.
  fill_solid( leds, NUM_LEDS, CRGB(255,0,0));
  FastLED.show();
  delay (300);
  fill_solid( leds, NUM_LEDS, CRGB(0,255,0));
  FastLED.show();
  delay (300);
  fill_solid( leds, NUM_LEDS, CRGB(0,0,255));
  FastLED.show();
  delay (300);
  FastLED.clear ();
  FastLED.show();
  
} // this bracket closes the setup loop. This loop plays only once. Part of it is the opening statement above anouncing gameplay will BEGIN!

//---------------------------------------------------------------------------
 
void loop() {

//the code below is the waiting effect
        while(dot < 6) { 
            leds[dot] = CRGB(0,5,0); // this sets a really dim processing light loopon the led strip.
            FastLED.show();
            
            delay(100);
            leds[dot] = CRGB::Black; // deactivate this one if you don;t want a load bar effect but a rollover effect
            
            dot++;
        }
  dot=0; // by placing this statement outside of the loop, the sketch is allowed to bontinue

}

void Odyletterswitch(){

/*
        // Option 1 for confirmation of choice this block counts down from 3. 
        // Question is if we prefer something like this, or prefer a x second delay.
        
         // The code below manages the Odyword letter indication LED's
        leds[6] = CRGB(50,0,0); // this switches LED6 on (light 7 -the eigth light- on the strip)
        FastLED.show();
        delay(1000);
        
        // The code below manages the Odyword letter indication LED's
        leds[6] = CRGB(0,0,50); // this switches LED6 on (light 7 -the eigth light- on the strip)
        FastLED.show();
        delay(1000); 
        }

      // The code below manages the Odyword letter indication LED's
      leds[7] = CRGB(0,0,50); // this switches LED7 light on (light 8 -the eigth light- on the strip)
      FastLED.show();
      
}
//---------------------------------------------------------------------------

void actiontrigger() {
  // The code below manages the Odyword letter indication LED's
  FastLED.clear (); // The action is only selected after each succesfull selected 2-letter odyword. That means the lamp indications for letter selection can be switched off.
  FastLED.show(); 
  }

//---------------------------------------------------------------------------
void LampjesRood()
{ 
   for(int i = 0; i < NUM_LEDS; i++ )
   {
   leds[i].setRGB(255,0,255);  // Set Color HERE!!!
   leds[i].fadeLightBy(brightness);
  }
  FastLED.show();
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade: 
  if(brightness == 0 || brightness == 255)
  {
    fadeAmount = -fadeAmount ; 
  }    
  delay(9);  // This delay sets speed of the fade. I usually do from 5-75 but you can always go higher.
}
