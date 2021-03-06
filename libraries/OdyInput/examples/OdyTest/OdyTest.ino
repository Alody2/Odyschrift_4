#include "OdyInput.h"

int aantal_odytekens = 3;
int odyleft = 47;
int odyright= 49;
int odyup = 53;
int odydown = 51;
int bedenktijd = 888;
int holdtime = 888;
OdyInput odyinput(odyleft, odyright, odyup,odydown, bedenktijd, holdtime); //contacten van de joystick
#include "FastLED.h"
#define NUM_LEDS 12  // # of LEDS in the strip
CRGB leds[NUM_LEDS];
#define PIN 12 // ZIt op pin 12
#define COLOR_ORDER GRB  // I had to change this for my strip if your color is off then you know.
int fadeAmount = 25;  // Set the amount to fade I usually do 5, 10, 15, 20, 25 etc even up to 255.
int brightness = 0; 
		
String _Odywoord;
//---------------------------------------------------------------------------

void setup()
{
  	Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
	FastLED.addLeds<WS2812B, PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //setup voor de LED strip
       	leds[9] = CRGB(50,5,0); // this sets a really dim processing light loopon the led strip.      	leds[10] = CRGB(100,5,0); // this sets a really dim processing light loopon the led strip.
       	 leds[11] = CRGB(100,5,0); // this sets a really dim processing light loopon the led strip.
            FastLED.show();

}
//---------------------------------------------------------------------------
 
void loop()
{
char _Odyteken;
int _Odyled;
	_Odywoord = "";
	_Odyled = "";
	_Odywoord = odyinput.selectieJoystickDigitaal(aantal_odytekens);
	aantal_odytekens = 0;
	while (aantal_odytekens < aantal_odytekens)
	{
		switch (aantal_odytekens)
		{
			case 0:
				_Odyled = 6;
			break;
			case 1:
				_Odyled = 7;
			break;
			case 2:
				_Odyled = 8;
			break;
		}
		_Odyteken =odyinput.Odywoord.charAt(aantal_odytekens);
		if (_Odyteken == 'D' || _Odyteken == 'O')		
		{
Serial.println ("DO" );
           	 leds[_Odyled] = CRGB(200,5,0); // this sets a really dim processing light loopon the led strip.
		}
		else if (_Odyteken == 'R' || _Odyteken == 'E')		
		{
Serial.println ("ME" );
           	 leds[_Odyled] = CRGB(5,200,0); // this sets a really dim processing light loopon the led strip.
		}
		else if (_Odyteken == 'M' || _Odyteken == 'I')		
		{
Serial.println ("MI" );
           	 leds[_Odyled] = CRGB(5,0,200); // this sets a really dim processing light loopon the led strip.
		}
		else if (_Odyteken == 'F' || _Odyteken == 'A')		
		{
Serial.println ("FA" );
           	 leds[_Odyled] = CRGB(100,200,0); // this sets a really dim processing light loopon the led strip.
		}
		aantal_odytekens += 1;
	}
            FastLED.show();
}

//---------------------------------------------------------------------------

