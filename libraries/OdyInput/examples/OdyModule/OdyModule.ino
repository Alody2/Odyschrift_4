#include "OdyInput.h"
//#include "OdyAlgemeen.h"
#include <LiquidCrystal_I2C.h> // include the library code
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal_I2C lcd (0x27, 20, 4);
// Connect the I2C LCD to the SDA en SCL pin on the Arduino Mega!
#include "FastLED.h"
#include <EEPROM.h>
#define NUM_LEDS 12  // # of LEDS in the strip
CRGB leds[NUM_LEDS];
//schakelaars
int bedenktijd = 2000;
int teller; 
int holdtime = 50;
int _turntime = 50;

int aantal_odytekens = 1;
int odyleft = 47;
int odyright= 49;
int odyup = 53;
int odydown = 51;
OdyInput odyinput(odyleft, odyright, odyup,odydown, bedenktijd, holdtime); //contacten van de joystick
//OdyAlgemeen odyalgemeen();
int _mDO = 38;
int _mDE = 40;
int _mDI = 42;
int _mDA = 44;
int _mRO = 46;
int _mRE = 48;
int _mRI = 50;
int _mRA = 52;
bool _neutraal;
boolean afrollen;                   // waar als de tekst afgerold moet worden
String tekst;                       //catches the text to print to the lcd-screen
int beginTekst;                    //lengte van tekst, om de tekst af te kunnen rollen
int lengteTekst;                    //lengte van tekst, om de tekst af te kunnen rollen
int cursorKolom;                    //waar op de regel start de tekst
int cursorRij;                      //op welke regel start de tekst
boolean laatstaan;                  //waar als de tekst niet wordt weggepoetst na de pauze
int wachten;                        //bepaalt of en hoe lang gewacht wordt op de volgende tekst
bool wachtActie;                        //bepaalt of en hoe lang gewacht wordt op de volgende tekst
boolean firstGroup = true;          // This Boolean is used for zooming in on the group DRMF, or the group AOEI
int readtime = 3000;                // Sets the time the info will be on the screen for Elinde's written messages
#define PIN 12 // ZIt op pin 12
#define COLOR_ORDER GRB  // I had to change this for my strip if your color is off then you know.
int fadeAmount = 25;  // Set the amount to fade I usually do 5, 10, 15, 20, 25 etc even up to 255.
int brightness = 0; 

int i = 6;		
String _Odyteken;
String _Odywoord;
int Odyletternr;
String letter;
String letter2;
String woord;
String woord1;
String woord2;
String woord3;
int lengte;
int Odynummer = 64;
int _Odyled;
int oog;
long lngWorp = 0;
long lngHerhaal= 0;
int plaats;
int rood;
int groen;
int blauw;
int eeAddress = 0;
//---------------------------------------------------------------------------

void setup()
{
  	Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
	FastLED.addLeds<WS2812B, PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //setup voor de LED strip
  	lcd.init();
  	lcd.backlight();
	randomSeed (analogRead(4));
	lcd.clear();
 	pinMode(_mDO , OUTPUT); 
 	pinMode(_mDE , OUTPUT); 
 	pinMode(_mDI , OUTPUT); 
 	pinMode(_mDA , OUTPUT); 
 	pinMode(_mRO , OUTPUT); 
 	pinMode(_mRE , OUTPUT); 
 	pinMode(_mRI , OUTPUT); 
 	pinMode(_mRA , OUTPUT); 
	EEPROM.get(eeAddress,Odynummer);
	startModule();
}

void loop()
{
	switch (Odynummer)
	{
		case 1:
			tweeStap();	
		break;
		case 2:
			drieStap();	
		break;
		case 3:
			eenStap();	
		break;
		case 64:
			drieStap();
		break;
		default:
			Serial.print (Odynummer); 
			Serial.println ("Odynummer"); 
	}
}
//---------------------------------------------------------------------------
void eenStap()
{
	odyinput.overgang = false; 
	odyinput.selectieDRMF();
	switch (Odynummer)
	{	
		case 3:	
			odyinput.Odyteken = ' '; 
			dom_actie();
	}
}
void tweeStap()
{
	if (i == 6 && _neutraal == false)
	{
		while (_neutraal == false)
		{
			odyinput.firstLetterDefined = false; 
			_Odyteken = odyinput.selectieJoystickDigitaal(aantal_odytekens);
			lichtaan();
			_neutraal = true;
		}
		_Odywoord = _Odywoord + _Odyteken; 
		i = 7;
	}
	else if ( digitalRead( odyup ) == HIGH && digitalRead( odyright ) == HIGH &&	 digitalRead( odydown ) == HIGH && digitalRead( odyleft) == HIGH)
	{
		delay (holdtime);
		_neutraal = false;
	}
	else if (i == 7 && _neutraal == false)
	{
		while (_neutraal == false)
		{
			odyinput.firstLetterDefined = true; 
			_Odyteken = odyinput.selectieJoystickDigitaal(aantal_odytekens);
			lichtaan();
			_neutraal = true;
		}
		_Odywoord = _Odywoord + _Odyteken; 
		i = 6;
		switch (Odynummer)
		{
			case 1:
				dod_actie();
			break;
		}	
	}
}
void drieStap()
{
	if (i == 6 && _neutraal == false)
	{
		while (_neutraal == false)
		{
			odyinput.firstLetterDefined = false; 
			_Odyteken = odyinput.selectieJoystickDigitaal(aantal_odytekens);
			lichtaan();
			_neutraal = true;
		}
		_Odywoord = _Odywoord + _Odyteken; 
		i = 7;
	}
	else if ( digitalRead( odyup ) == HIGH && digitalRead( odyright ) == HIGH &&	 digitalRead( odydown ) == HIGH && digitalRead( odyleft) == HIGH)
	{
		delay (holdtime);
		_neutraal = false;
	}
	else if (i == 7 && _neutraal == false)
	{
		while (_neutraal == false)
		{
			odyinput.firstLetterDefined = true; 
			_Odyteken = odyinput.selectieJoystickDigitaal(aantal_odytekens);
			lichtaan();
			_neutraal = true;
		}
		_Odywoord = _Odywoord + _Odyteken; 
		i = 8;
	}
	else if (i == 8 && _neutraal == false)
	{
		while (_neutraal == false)
		{
			odyinput.firstLetterDefined = false; 
			_Odyteken = odyinput.selectieJoystickDigitaal(aantal_odytekens);
			lichtaan();
			_neutraal = true;
		}
		_Odywoord = _Odywoord + _Odyteken; 
		i = 6;
		switch (Odynummer)
		{	
			case 2:
				dor_actie();
			break;
			case 64:
				actie();
			break;
		}	
	}
}
void lichtaan()
{
	if (_Odyteken == "D" || _Odyteken == "O")		
	{
   		leds[i] = CRGB(200,5,0); 
	}
	else if (_Odyteken == "R" || _Odyteken == "E")		
	{
   	 	leds[i] = CRGB(5,200,0);
	}
	else if (_Odyteken == "M" || _Odyteken == "I")		
	{
   	 	leds[i] = CRGB(5,0,200);
	}
	else if (_Odyteken == "F" || _Odyteken == "A")		
	{
   	 	leds[i] = CRGB(100,200,0);
	}
	odyinput.overgang = false; 
        FastLED.show();

}
void instellenmodule()
{
	leds[6] = CRGB(0,0,0); 
	leds[7] = CRGB(0,0,0);
	leds[8] = CRGB(0,0,0);
       	leds[9] = CRGB(50,200,0); 
  	leds[10] = CRGB(50,200,0);
  	leds[11] = CRGB(50,200,0);
	FastLED.show();
	lcd.clear();
	Odynummer = 64;
  	tekst = "Terug: F, FA, FAF"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  	tekst = "DOD = 4 op een rij"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  	tekst = "DOR = schrijven"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 1; laatstaan = true; lcd_print();    
  	tekst = "DOM = dobbelsteen"; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 3; laatstaan = true; lcd_print(); 
	EEPROM.put (eeAddress,Odynummer);
}
//---------------------------------------------------------------------------
void actie()
{
	if (_Odywoord== "DOD")
	{
		//vieroprij
		Odynummer = 1;
		dod_begin();
	}
	else if (_Odywoord=="DOR")
	{
		Odynummer = 2;
		dor_begin();
	}
	else if (_Odywoord=="DOM")
	{
		//dobbelstenen werpen
		dom_begin();
		Odynummer = 3;
	}
	else if (_Odywoord=="DOF")
	{
		Odynummer = 4;instellenmodule();
	}
	if (_Odywoord== "DED")
	{
		Odynummer = 5;instellenmodule();
	}
	else if (_Odywoord=="DER")
	{
		Odynummer = 6;instellenmodule();
	}
	else if (_Odywoord=="DEM")
	{
		Odynummer = 7;instellenmodule();
	}
	else if (_Odywoord=="DEF")
	{
		Odynummer = 8;instellenmodule();
	}
	if (_Odywoord== "DID")
	{
		Odynummer = 9;instellenmodule();
	}
	else if (_Odywoord=="DIR")
	{
		Odynummer = 10;instellenmodule();
	}
	else if (_Odywoord=="DIM")
	{
		Odynummer = 11;instellenmodule();
	}
	else if (_Odywoord=="DIF")
	{
		Odynummer = 12;instellenmodule();
	}
	else if (_Odywoord== "DAD")
	{
		Odynummer = 13;instellenmodule();
	}
	else if (_Odywoord=="DAR")
	{
		Odynummer = 14;instellenmodule();
	}
	else if (_Odywoord=="DAM")
	{
		Odynummer = 15;instellenmodule();
	}
	else if (_Odywoord=="DAF")
	{
		Odynummer = 16;instellenmodule();
	}
	else if (_Odywoord== "ROD")
	{
		Odynummer = 17;instellenmodule();
	}
	else if (_Odywoord=="ROR")
	{
		Odynummer = 18;instellenmodule();
	}
	else if (_Odywoord=="ROM")
	{
		Odynummer = 19;instellenmodule();
	}
	else if (_Odywoord=="ROF")
	{
		Odynummer = 20;instellenmodule();
	}
	else if (_Odywoord== "RED")
	{
		Odynummer = 21;instellenmodule();
	}
	else if (_Odywoord=="RER")
	{
		Odynummer = 22;instellenmodule();
	}
	else if (_Odywoord=="REM")
	{
		Odynummer = 23;instellenmodule();
	}
	else if (_Odywoord=="REF")
	{
		Odynummer = 24;instellenmodule();
	}
	if (_Odywoord== "RID")
	{
		Odynummer = 25;instellenmodule();
	}
	else if (_Odywoord=="RIR")
	{
		Odynummer = 26;instellenmodule();
	}
	else if (_Odywoord=="RIM")
	{
		Odynummer = 27;instellenmodule();
	}
	else if (_Odywoord=="RIF")
	{
		Odynummer = 28;instellenmodule();
	}
	else if (_Odywoord== "RAD")
	{
		Odynummer = 29;instellenmodule();
	}
	else if (_Odywoord=="RAR")
	{
		Odynummer = 30;instellenmodule();
	}
	else if (_Odywoord=="RAM")
	{
		Odynummer = 31;instellenmodule();
	}
	else if (_Odywoord=="RAF")
	{
		Odynummer = 32;instellenmodule();
	}
	else if (_Odywoord== "MOD")
	{
		Odynummer = 33;instellenmodule();
	}
	else if (_Odywoord=="MOR")
	{
		Odynummer = 34;instellenmodule();
	}
	else if (_Odywoord=="MOM")
	{
		Odynummer = 35;instellenmodule();
	}
	else if (_Odywoord=="MOF")
	{
		Odynummer = 36;instellenmodule();
	}
	else if (_Odywoord== "MED")
	{
		Odynummer = 37;instellenmodule();
	}
	else if (_Odywoord=="MER")
	{
		Odynummer = 38;instellenmodule();
	}
	else if (_Odywoord=="MEM")
	{
		Odynummer = 39;instellenmodule();
	}
	else if (_Odywoord=="MEF")
	{
		Odynummer = 40;instellenmodule();
	}
	else if (_Odywoord== "MID")
	{
		Odynummer = 41;instellenmodule();
	}
	else if (_Odywoord=="MIR")
	{
		Odynummer = 42;instellenmodule();
	}
	else if (_Odywoord=="MIM")
	{
		Odynummer = 43;instellenmodule();
	}
	else if (_Odywoord=="MIF")
	{
		Odynummer = 44;instellenmodule();
	}
	else if (_Odywoord== "MAD")
	{
		Odynummer = 45;instellenmodule();
	}
	else if (_Odywoord=="MAR")
	{
		Odynummer = 46;instellenmodule();
	}
	else if (_Odywoord=="MAM")
	{
		Odynummer = 47;instellenmodule();
	}
	else if (_Odywoord=="MAF")
	{
		Odynummer = 48;instellenmodule();
	}
	else if (_Odywoord== "FOD")
	{
		Odynummer = 49;instellenmodule();
	}
	else if (_Odywoord=="FOR")
	{
		Odynummer = 50;instellenmodule();
	}
	else if (_Odywoord=="FOM")
	{
		Odynummer = 51;instellenmodule();
	}
	else if (_Odywoord=="FOF")
	{
		Odynummer = 52;instellenmodule();
	}
	else if (_Odywoord== "FED")
	{
		Odynummer = 53;instellenmodule();
	}
	else if (_Odywoord=="FER")
	{
		Odynummer = 54;instellenmodule();
	}
	else if (_Odywoord=="FEM")
	{
		Odynummer = 55;instellenmodule();
	}
	else if (_Odywoord=="FEF")
	{
		Odynummer = 56;instellenmodule();
	}
	else if (_Odywoord== "FID")
	{
		Odynummer = 57;instellenmodule();
	}
	else if (_Odywoord=="FIR")
	{
		Odynummer = 58;instellenmodule();
	}
	else if (_Odywoord=="FIM")
	{
		Odynummer = 59;instellenmodule();
	}
	else if (_Odywoord=="FIF")
	{
		Odynummer = 60;instellenmodule();
	}
	else if (_Odywoord== "FAD")
	{
		Odynummer = 61;
	}
	else if (_Odywoord=="FAR")
	{
			Odynummer = 62;
	}
	else if (_Odywoord=="FAM")
	{
			Odynummer = 63;
	}

	else if (_Odywoord=="FAF")
	{
			Odynummer = 64;
	}
	EEPROM.put (eeAddress,Odynummer);
	_Odywoord = ""; 
} 
//---------------------------------------------------------------------------
void startModule()
{
	switch (Odynummer)
	{
		case 1:
			dod_begin();
		break;
		case 2:
			dor_begin();
		break;
		case 3:
Serial.print ("B2");
			dom_begin();
		break;
		case 64:
			instellenmodule();
		break;
	}
} 
void lcd_print()
{ 
  
  /* 
  This is function that can be called to regulate printing to the I2C-lcd-screen  
  */            
	lcd.setCursor(cursorKolom, cursorRij);
	lengteTekst = tekst.length();
	
	if (afrollen == true)
	{ // This part executes what needs to happen to have the "afrollen" effect
	
	    	for (int i = 0; i < lengteTekst; i++) 
		{
	      		delay(70); // this sets the time it takes between letter appearing
			lcd.print(tekst.charAt(i));   // Print a message to the LCD.
	    	}
	} 
	 
	else 	
	{
	  	lcd.print (tekst);
	} 
	
	while (wachten > 1) 
	{
	  	delay(500);            // wait X amount of Milli-sec
	  	wachten = wachten - 1;
	}
	
	if (laatstaan == false)
	{
		lcd.clear(); // clear
  	}
}

