#include "OdyInput.h"

#include <LiquidCrystal_I2C.h> // include the library code
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal_I2C lcd (0x27, 20, 4);
// Connect the I2C LCD to the SDA en SCL pin on the Arduino Mega!
#include "FastLED.h"
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
int lengteTekst;                    //lengte van tekst, om de tekst af te kunnen rollen
int cursorKolom;                    //waar op de regel start de tekst
int cursorRij;                      //op welke regel start de tekst
boolean laatstaan;                  //waar als de tekst niet wordt weggepoetst na de pauze
int wachten;                        //bepaalt of en hoe lang gewacht wordt op de volgende tekst
boolean Firstgroup = true;          // This Boolean is used for zooming in on the group DRMF, or the group AOEI
int readtime = 3000;                // Sets the time the info will be on the screen for Elinde's written messages
#define PIN 12 // ZIt op pin 12
#define COLOR_ORDER GRB  // I had to change this for my strip if your color is off then you know.
int fadeAmount = 25;  // Set the amount to fade I usually do 5, 10, 15, 20, 25 etc even up to 255.
int brightness = 0; 

int i = 6;		
String _Odyteken;
String _Odywoord;
char letter;
String woord;
int _Odynummer;
int _Odyled;
//---------------------------------------------------------------------------

void setup()
{
  	Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
	FastLED.addLeds<WS2812B, PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //setup voor de LED strip
  lcd.init();
  lcd.backlight();
  
  tekst = "LATEN WE"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  tekst = "SPELLEN"; cursorKolom = 9 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  tekst = "NU:"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 1; laatstaan = true; lcd_print();    
  tekst = "Schrijven"; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 6; laatstaan = false; lcd_print(); 
       	leds[9] = CRGB(50,5,0); // this sets a really dim processing light loopon the led strip.    
  	leds[10] = CRGB(50,5,0); // this sets a really dim processing light loopon the led strip.
  	leds[11] = CRGB(0,50,0); // this sets a really dim processing light loopon the led strip.
	FastLED.show();
}

void loop()
{
	if (i == 6 && _neutraal == false)
	{
		odyinput.firstLetterDefined = false; 
		_Odyteken = odyinput.selectieJoystickDigitaal(aantal_odytekens);
		lichtaan(i);
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
		odyinput.firstLetterDefined = true; 
		_Odyteken = odyinput.selectieJoystickDigitaal(aantal_odytekens);
		lichtaan(i);
		_Odywoord = _Odywoord + _Odyteken; 
		i = 8;
	}
	else if (i == 8 && _neutraal == false)
	{
		odyinput.firstLetterDefined = false; 
		_Odyteken = odyinput.selectieJoystickDigitaal(aantal_odytekens);
		lichtaan(i);
		_Odywoord = _Odywoord + _Odyteken; 
		actie ();
		i = 6;
	}
}
//---------------------------------------------------------------------------
void lichtaan(int lichtaan)
{
	if (_Odyteken == "D" || _Odyteken == "O")		
	{
   		leds[lichtaan] = CRGB(200,5,0); // this sets a really dim processing light loopon the led strip.
	}
	else if (_Odyteken == "R" || _Odyteken == "E")		
	{
   	 	leds[lichtaan] = CRGB(5,200,0); // this sets a really dim processing light loopon the led strip.
	}
	else if (_Odyteken == "M" || _Odyteken == "I")		
	{
   	 	leds[lichtaan] = CRGB(5,0,200); // this sets a really dim processing light loopon the led strip.
	}
	else if (_Odyteken == "F" || _Odyteken == "A")		
	{
   	 	leds[lichtaan] = CRGB(100,200,0); // this sets a really dim processing light loopon the led strip.
	}
	odyinput.overgang = false; 
	_neutraal = true;
        FastLED.show();

}
//---------------------------------------------------------------------------
void actie()
{
	if (_Odywoord== "DOD")
	{
		_Odynummer = 1;
		letter = 'a';
	}
	else if (_Odywoord=="DOR")
	{
		_Odynummer = 2;
		letter = 'b';
	}
	else if (_Odywoord=="DOM")
	{
		_Odynummer = 3;
		letter = 'c';
	}
	else if (_Odywoord=="DOF")
	{
		_Odynummer = 4;
		letter = 'd';
	}
	if (_Odywoord== "DED")
	{
		_Odynummer = 5;
		letter = 'e';
	}
	else if (_Odywoord=="DER")
	{
		_Odynummer = 6;
		letter = 'f';
	}
	else if (_Odywoord=="DEM")
	{
		_Odynummer = 7;
		letter = 'g';
	}
	else if (_Odywoord=="DEF")
	{
		_Odynummer = 8;
		letter = 'h';
	}
	if (_Odywoord== "DID")
	{
		_Odynummer = 9;
		letter = 'i';
	}
	else if (_Odywoord=="DIR")
	{
		_Odynummer = 10;
		letter = 'j';
	}
	else if (_Odywoord=="DIM")
	{
		_Odynummer = 11;
		letter = 'k';
	}
	else if (_Odywoord=="DIF")
	{
		_Odynummer = 12;
		letter = 'l';
	}
	else if (_Odywoord== "DAD")
	{
		_Odynummer = 13;
		letter = 'm';
	}
	else if (_Odywoord=="DAR")
	{
		_Odynummer = 14;
		letter = 'n';
	}
	else if (_Odywoord=="DAM")
	{
		_Odynummer = 15;
		letter = 'o';
	}
	else if (_Odywoord=="DAF")
	{
		_Odynummer = 16;
		letter = 'p';
	}
	else if (_Odywoord== "ROD")
	{
		_Odynummer = 17;
		letter = 'q';
	}
	else if (_Odywoord=="ROR")
	{
		_Odynummer = 18;
		letter = 'r';
	}
	else if (_Odywoord=="ROM")
	{
		_Odynummer = 19;
		letter = 's';
	}
	else if (_Odywoord=="ROF")
	{
		_Odynummer = 20;
		letter = 't';
	}
	else if (_Odywoord== "RED")
	{
		_Odynummer = 21;
		letter = 'u';
	}
	else if (_Odywoord=="RER")
	{
		_Odynummer = 22;
		letter = 'v';
	}
	else if (_Odywoord=="REM")
	{
		_Odynummer = 23;
		letter = 'w';
	}
	else if (_Odywoord=="REF")
	{
		_Odynummer = 24;
		letter = 'x';
	}
	if (_Odywoord== "RID")
	{
		_Odynummer = 25;
		letter = 'y';
	}
	else if (_Odywoord=="RIR")
	{
		_Odynummer = 26;
		letter = 'z';
	}
	else if (_Odywoord=="RIM")
	{
		_Odynummer = 27;
		letter = '1';
	}
	else if (_Odywoord=="RIF")
	{
		_Odynummer = 28;
		letter = '2';
	}
	else if (_Odywoord== "RAD")
	{
		_Odynummer = 29;
		letter = '3';
	}
	else if (_Odywoord=="RAR")
	{
		_Odynummer = 30;
		letter = '4';
	}
	else if (_Odywoord=="RAM")
	{
		_Odynummer = 31;
		letter = '5';
	}
	else if (_Odywoord=="RAF")
	{
		_Odynummer = 32;
		letter = '6';
	}
	else if (_Odywoord== "MOD")
	{
		_Odynummer = 33;
		letter = '7';
	}
	else if (_Odywoord=="MOR")
	{
		_Odynummer = 34;
		letter = '8';
	}
	else if (_Odywoord=="MOM")
	{
		_Odynummer = 35;
		letter = '9';
	}
	else if (_Odywoord=="MOF")
	{
		_Odynummer = 36;
		letter = '0';
	}
	else if (_Odywoord== "MED")
	{
		_Odynummer = 37;
		letter = '+';
	}
	else if (_Odywoord=="MER")
	{
		_Odynummer = 38;
		letter = '-';
	}
	else if (_Odywoord=="MEM")
	{
		_Odynummer = 39;
		letter = '*';
	}
	else if (_Odywoord=="MEF")
	{
		_Odynummer = 40;
		letter = '/';
	}
	else if (_Odywoord== "MID")
	{
		_Odynummer = 41;
		letter = '=';
	}
	else if (_Odywoord=="MIR")
	{
		_Odynummer = 42;
		letter = '.';
	}
	else if (_Odywoord=="MIM")
	{
		_Odynummer = 43;
		letter = ',';
	}
	else if (_Odywoord=="MIF")
	{
		_Odynummer = 44;
		letter = '?';
	}
	else if (_Odywoord== "MAD")
	{
		_Odynummer = 45;
		letter = ';';
	}
	else if (_Odywoord=="MAR")
	{
		_Odynummer = 46;
		letter = ':';
	}
	else if (_Odywoord=="MAM")
	{
		_Odynummer = 47;
		letter = 'au';
	}
	else if (_Odywoord=="MAF")
	{
		_Odynummer = 48;
		letter = 'oo';
	}
	else if (_Odywoord== "FOD")
	{
		_Odynummer = 49;
		letter = 'oe';
	}
	else if (_Odywoord=="FOR")
	{
		_Odynummer = 50;
		letter = 'aa';
	}
	else if (_Odywoord=="FOM")
	{
		_Odynummer = 51;
		letter = 'ge';
	}
	else if (_Odywoord=="FOF")
	{
		_Odynummer = 52;
		letter = 'ver';
	}
	else if (_Odywoord== "FED")
	{
		_Odynummer = 53;
		letter = 'sch';
	}
	else if (_Odywoord=="FER")
	{
		_Odynummer = 54;
		letter = 'st';
	}
	else if (_Odywoord=="FEM")
	{
		_Odynummer = 55;
		letter = 'ing';
	}
	else if (_Odywoord=="FEF")
	{
		_Odynummer = 56;
		letter = 'heid';
	}
	else if (_Odywoord== "FID")
	{
		_Odynummer = 57;
		letter = 'zw';
	}
	else if (_Odywoord=="FIR")
	{
		_Odynummer = 58;
		letter = 'isch';
	}
	else if (_Odywoord=="FIM")
	{
		_Odynummer = 59;
		letter = 'cht';
	}
	else if (_Odywoord=="FIF")
	{
		_Odynummer = 60;
		letter = ' ';
	}
	else if (_Odywoord== "FAD")
	{
		_Odynummer = 61;
		letter = 'a';
	}
	else if (_Odywoord=="FAR")
	{
			_Odynummer = 62;
			letter = 'a';
	}
	else if (_Odywoord=="FAM")
	{
			_Odynummer = 63;
			letter = 'a';
	}
	else if (_Odywoord=="FAF")
	{
			_Odynummer = 64;
			letter = 'a';
	}
	
    	tekst =  _Odywoord + " " + _Odynummer ; cursorKolom = 0 ; cursorRij = 0; wachten = 1; laatstaan = true; lcd_print();    
	woord = woord + letter;
   	tekst =  woord ; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
			
	_Odywoord = "";
	_neutraal = false;
	teller = bedenktijd;
	while (teller > 0)
	{
		delay (1);
		teller -= 1;
	}
	leds[6] = CRGB(0,0,0); // this sets a really dim processing light loopon the led strip.
	leds[7] = CRGB(0,0,0); // this sets a really dim processing light loopon the led strip.
	leds[8] = CRGB(0,0,0); // this sets a really dim processing light loopon the led strip.
        FastLED.show();
} 
//---------------------------------------------------------------------------

void lcd_print(){ 
  
  /* 
  This is function that can be called to regulate printing to the I2C-lcd-screen  
  */            
  lcd.setCursor(cursorKolom, cursorRij);
  lengteTekst = tekst.length();
 
  if (afrollen == true){ // This part executes what needs to happen to have the "afrollen" effect
 
      for (int i = 0; i < lengteTekst; i++) {
        delay(70); // this sets the time it takes between letter appearing
        lcd.print(tekst.charAt(i));   // Print a message to the LCD.
      }
   } 
   
  else {
    lcd.print (tekst);
    } 
 
  while (wachten > 1) {
    delay(500);            // wait X amount of Milli-sec
    wachten = wachten - 1;
    }
  
  if (laatstaan == false){
    lcd.clear(); // clear
  }
}
