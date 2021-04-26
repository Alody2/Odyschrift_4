#include "OdyLed.h"
OdyLed odyled(	47,49,53,51, //contacten van de joystick
		12, //aantal ledjes
		12 //pin voor ledjes
				
);
String _Odyled;
//---------------------------------------------------------------------------

void setup()
{
  	Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
}
//---------------------------------------------------------------------------
 
void loop()
{
_Odywoord = "";
	_Odyled = odyled.selectieJoystickDigitaal(2);
Serial.println (_Odywoord);
}

//---------------------------------------------------------------------------

