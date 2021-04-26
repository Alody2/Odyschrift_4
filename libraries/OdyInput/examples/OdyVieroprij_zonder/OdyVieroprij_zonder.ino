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
int _Odyled;
//---------------------------------------------------------------------------

void setup()
{
  	Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
	FastLED.addLeds<WS2812B, PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //setup voor de LED strip
       	leds[9] = CRGB(50,5,0); // this sets a really dim processing light loopon the led strip.    
  	leds[10] = CRGB(50,5,0); // this sets a really dim processing light loopon the led strip.
  	leds[11] = CRGB(50,5,0); // this sets a really dim processing light loopon the led strip.
  pinMode(_mDO , OUTPUT); 
  pinMode(_mDE , OUTPUT); 
  pinMode(_mDI , OUTPUT); 
  pinMode(_mDA , OUTPUT); 
  pinMode(_mRO , OUTPUT); 
  pinMode(_mRE , OUTPUT); 
  pinMode(_mRI , OUTPUT); 
  pinMode(_mRA , OUTPUT); 
  lcd.init();
  lcd.backlight();
  
  tekst = "LATEN WE"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  tekst = "SPEL(L)EN"; cursorKolom = 9 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  tekst = "NU:"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 1; laatstaan = true; lcd_print();    
  tekst = "Vier op een rij"; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 6; laatstaan = false; lcd_print(); 
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
Serial.print (i); 
Serial.print ("tweede"); 
		lichtaan(i);
		_Odywoord = _Odywoord + _Odyteken; 
		actie ();
		i = 6;
	}
}
//---------------------------------------------------------------------------
void lichtaan(int lichtaan)
{
Serial.print (i); 
Serial.print ("in"); 
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
	if (_Odywoord == "DO")
	{
    	tekst = "Chip DO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mDO, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDO, LOW);
	}
	if (_Odywoord == "DE")
	{
    tekst = "Chip DE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mDE, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDE, LOW);
	}
	if (_Odywoord == "DI")
	{
    tekst = "Chip DI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mDI, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDI, LOW);
	}
	if (_Odywoord == "DA")
	{
    tekst = "Chip DA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mDA, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDA, LOW);
	}
	if (_Odywoord == "RO")
	{
    tekst = "Chip RO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mRO, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRO, LOW);
	}
	if (_Odywoord == "RE")
	{
    tekst = "Chip RE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mRE, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRE, LOW);
	}
	if (_Odywoord == "RI")
	{
    tekst = "Chip RI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mRI, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRI, LOW);
	}
	if (_Odywoord == "RA")
	{
    tekst = "Chip RA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mRA, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRA, LOW);
	}
	else if (_Odywoord == "ME")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	 }
	else if (_Odywoord == "MI")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	}
	else if (_Odywoord == "MA")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	}
	else if (_Odywoord == "FO")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	}
	else if (_Odywoord == "FE")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	}
	else if (_Odywoord == "FI")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	}
	else if (_Odywoord == "FA")
	{
	  	tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 1; laatstaan = true; lcd_print(); // 20 letters op rij 1
		delay (readtime);
	  	lcd.clear(); // clear
	}
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
        FastLED.show();
Serial.print(_Odywoord);

	
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
