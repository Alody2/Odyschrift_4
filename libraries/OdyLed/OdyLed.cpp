 
/* 
This library adapts the Arduino-library FastLed for use in Odyschrift. Odyschrift , for short Ody is an input method. It uses 4 different impulses, in two flavours. It has been originally created by Alle v Meeteren and Jurre Ongering on spring 2020. 

 * The first implementation is a joystick which can can sense activation on a single contact (allowing 4 directions)  or 2 contacts (allowing for 4 directions between the other 4 directions) at a time.
 * In the neutral state none of these is active. In our implementation the joystick has to return to that neutral state, before the next direction can be chosen.
 * We alternate between the 2 groups, so there is a variable to indicate which group is the active group. 

 */

#include "Arduino.h"
#include "FastLED.h"
#include "OdyInput.h"
#include "OdyLed.h"
OdyLed::OdyLed(
				int dirLeft,
				int dirRight,
				int dirUp,
				int dirDown,
				int numleds, //aantal ledjes,
				int pinled //pin waaraan de matrix ledjes is verbonden,	
		)
{
  	pinMode( dirUp , INPUT);
 	pinMode( dirRight , INPUT);
  	pinMode( dirDown , INPUT);
  	pinMode( dirLeft , INPUT);
		
}
String OdyLed::selectieJoystickDigitaal()
{
}
