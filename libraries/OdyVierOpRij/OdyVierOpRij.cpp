/* 

  MorsierOpRij.cpp - Library for Vier op een rij.
  Created by Alle van Meeteren 4 april 2020.
  Released into the public domain.

It is part of the Odyschrift project. It has been originally created by Alle v Meeteren, modified by Jurre Ongering on 15 March 2020 amd conversed to a library on 4 avril 2020 by Alle
This module of the project enables physically handicapped people to play a game of "connect-four". A joystick is used as a controller. 
The joystick has 8 contacts.

 * The joystick can activate a single contact (4 directions)  or 2 contacts (4 directions between the other 4 directions) at a time.
 * In the neutral state none of these is active. In our implementation the joystick has to return to that neutral state, before the next direction can be chosen.
 * We alternate between the 2 groups, so there is a variable to indicate which group is the active group. 

We use an Arduino Mega */
#include "Arduino.h"
#include "OdyVierOpRij.h"
OdyVierOpRij::OdyVierOpRij(int mDO, int mDE, int mDI,int mDA,int mRO,int mRE,int mRI,int mRA)
{
  	pinMode(mDO , OUTPUT); 
	pinMode(mDE , OUTPUT); 
	pinMode(mDI , OUTPUT); 
	pinMode(mDA , OUTPUT); 
	pinMode(mRO , OUTPUT); 
	pinMode(mRE , OUTPUT); 
	pinMode(mRI , OUTPUT); 
	pinMode(mRA , OUTPUT); 
	_mDO =mDO;
	_mDE =mDE;
	_mDI =mDI;
	_mDA =mDA;
	_mRO =mRO;
	_mRE =mRE;
	_mRI =mRI;
	_mRA =mRA;
	_turntime = 70;
}
void OdyVierOpRij::actie(String Odywoord)
{
	if (Odywoord == "DO")
	{
    		delay (_turntime);
   		digitalWrite (_mDO, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDO, LOW);
	}
	if (Odywoord == "DE")
	{
    		delay (_turntime);
   		digitalWrite (_mDE, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDE, LOW);
	}
	if (Odywoord == "DI")
	{
    		delay (_turntime);
   		digitalWrite (_mDI, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDI, LOW);
	}
	if (Odywoord == "DA")
	{
    		delay (_turntime);
   		digitalWrite (_mDA, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDA, LOW);
	}
	if (Odywoord == "RO")
	{
    		delay (_turntime);
   		digitalWrite (_mRO, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRO, LOW);
	}
	if (Odywoord == "RE")
	{
    		delay (_turntime);
   		digitalWrite (_mRE, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRE, LOW);
	}
	if (Odywoord == "RI")
	{
    		delay (_turntime);
   		digitalWrite (_mRI, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRI, LOW);
	}
	if (Odywoord == "RA")
	{
    		delay (_turntime);
   		digitalWrite (_mRA, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRA, LOW);
	}
	if (Odywoord == "FA")
	{
		//naar switchen van module
	}

}
	
/*
void OdyVierOpRij::action(char Odywoord)
{
// checkcontact ("action");
	if (Odywoord == "DO")
	{
    	\\	tekst = "Chip DO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (turntime);
   		digitalWrite (_mDO, HIGH);
    		delay (turntime);
   		digitalWrite (_mDO, LOW);
     	}
  	else if (Odywoord =	= "DE")
	{
    	\\	tekst = "Chip DE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
   		 delay (turntime);
    		digitalWrite (_mDE, HIGH);
    		delay (turntime);
    		digitalWrite (_mDE, LOW);
    	}
  	else if (Odywoord == "DI")
	{
    	\\	tekst = "Chip DI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (turntime);
    		digitalWrite (_mDI, HIGH);
    		delay (turntime);
    		digitalWrite (_mDI, LOW);
    	}
  	else if (Odywoord == "DA")
	{
    	\\	tekst = "Chip DA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (turntime);
    		digitalWrite (_mDA, HIGH);
    		delay (turntime);
    		digitalWrite (_mDA, LOW);
    	}
 	else if (Odywoord == "RO")
	{
    	\\	tekst = "Chip RO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (turntime);
    		digitalWrite (_mRO, HIGH);
    		delay (turntime);
   		digitalWrite (_mRO, LOW);
    	}
 	else if (Odywoord == "RE")
	{
    	\\	tekst = "Chip RE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (turntime);
    		digitalWrite (_mRE, HIGH);
    		delay (turntime);
    		digitalWrite (_mRE, LOW);
    	}
  	else if (Odywoord == "RI")
	{
    	\\	tekst = "Chip RI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
   		delay (turntime);
    		digitalWrite (_mRI, HIGH);
    		delay (turntime);
    		digitalWrite (_mRI, LOW);
     	}
 	else if (Odywoord == "RA")
	{
    	\\	tekst = "Chip RA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (turntime);
    		digitalWrite (_mRA, HIGH);
    		delay (turntime);
    		digitalWrite (_mRA, LOW);
    	}
	
  	else if (Odywoord == "MO")
	{
    		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
   		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    			tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    		delay (3000);
    		lcd.clear(); // clear
    	}
  	else if (Odywoord == "ME")
	{
    		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
   		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    			tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    		delay (3000);
    		lcd.clear(); // clear
    	}
  	else if (Odywoord == "MI")
	{
    		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
   		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    			tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    		delay (3000);
    		lcd.clear(); // clear
    	}
  	else if (Odywoord == "MA")
	{
    		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
   		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    			tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    		delay (3000);
    		lcd.clear(); // clear
    	}
  	else if (Odywoord == "FO")
	{
    		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
   		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    			tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    		delay (3000);
    		lcd.clear(); // clear
    	}
  	else if (Odywoord == "FE")
	{
    		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
   		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    			tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    		delay (3000);
    		lcd.clear(); // clear
	}
  	else if (Odywoord == "FI")
	{
    		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
   		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    			tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    		delay (3000);
    		lcd.clear(); // clear
	}
  	else if (Odywoord == "FA")
	{
    		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
   		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    			tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    		delay (3000);
    		lcd.clear(); // clear
    	}
    	
  }
*/
    	
