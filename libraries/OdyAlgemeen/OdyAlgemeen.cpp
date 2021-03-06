/*
  OdyAlgemeen.cpp - Library Odyschrift. A system to select an item in a collection of items with a penstroke or an Arcade joystick.
  Created by A. van Meeteren, 2019.
  Released into the public domain.
*/
#include "Arduino.h"
#include "OdyAlgemeen.h"

OdyAlgemeen::OdyAlgemeen()
{
}

void OdyAlgemeen::regeltModule(int odyModule)
{
	switch (Odywoord.length())
	{
		/*
	case 1:
	break; */
	case 2:
	break;
	case 3:
	break; 
	case 5:
	break;
	case 4:
	break;
	}
}
int OdyAlgemeen::NaarNummer(String _Odywoord)
{
Serial.print ("dit");
/*
	Odywoord = _Odywoord;
	if (_Odywoord== "D")
	{
		_Odynummer = 1;
	}
	else if(_Odywoord== "R")
	{
		_Odynummer = 2;
	}
	else if (_Odywoord== "M")
	{
		_Odynummer = 3;
	}
	else if (_Odywoord== "F")
	{
		_Odynummer = 64;
	}
	else if(_Odywoord== "DO")
	{
		_Odynummer = 1;
	}
	else if (_Odywoord== "DE")
	{
		_Odynummer = 2;
	}
	else if (_Odywoord== "DI")
	{
		_Odynummer = 3;
	}
	else if(_Odywoord== "DA")
	{
		_Odynummer = 4;
	}
	else if (_Odywoord== "RO")
	{
		_Odynummer = 5;
	}
	else if (_Odywoord== "RE")
	{
		_Odynummer = 6;
	}
	else if(_Odywoord== "RI")
	{
		_Odynummer = 7;
	}
	else if (_Odywoord== "RA")
	{
		_Odynummer = 8;
	}
	else if (_Odywoord== "MO")
	{
		_Odynummer = 9;
	}
	else if (_Odywoord== "ME")
	{
		_Odynummer = 10;
	}
	else if(_Odywoord== "MI")
	{
		_Odynummer = 11;
	}
	else if (_Odywoord== "MA")
	{
		_Odynummer = 12;
	}
	else if (_Odywoord== "FO")
	{
		_Odynummer = 13;
	}
	else if(_Odywoord== "FE")
	{
		_Odynummer = 14;
	}
	else if (_Odywoord== "FI")
	{
		_Odynummer = 15;
	}
	else if (_Odywoord== "FA")
	{
		_Odynummer = 64;
	}
	else if (_Odywoord== "DOD")
	{
		_Odynummer = 1;
	}
	else if (_Odywoord=="DOR")
	{
		_Odynummer = 2;
	}
	else if (_Odywoord=="DOM")
	{
		_Odynummer = 3;
	}
	else if (_Odywoord=="DOF")
	{
		_Odynummer = 4;
	}
	if (_Odywoord== "DED")
	{
		_Odynummer = 5;
	}
	else if (_Odywoord=="DER")
	{
		_Odynummer = 6;
	}
	else if (_Odywoord=="DEM")
	{
		_Odynummer = 7;
	}
	else if (_Odywoord=="DEF")
	{
		_Odynummer = 8;
	}
	if (_Odywoord== "DID")
	{
		_Odynummer = 9;
	}
	else if (_Odywoord=="DIR")
	{
		_Odynummer = 10;
	}
	else if (_Odywoord=="DIM")
	{
		_Odynummer = 11;
	}
	else if (_Odywoord=="DIF")
	{
		_Odynummer = 12;
	}
	else if (_Odywoord== "DAD")
	{
		_Odynummer = 13;
	}
	else if (_Odywoord=="DAR")
	{
		_Odynummer = 14;
	}
	else if (_Odywoord=="DAM")
	{
		_Odynummer = 15;
	}
	else if (_Odywoord=="DAF")
	{
		_Odynummer = 16;
	}
	else if (_Odywoord== "ROD")
	{
		_Odynummer = 17;
	}
	else if (_Odywoord=="ROR")
	{
		_Odynummer = 18;
	}
	else if (_Odywoord=="ROM")
	{
		_Odynummer = 19;
	}
	else if (_Odywoord=="ROF")
	{
		_Odynummer = 20;
	}
	else if (_Odywoord== "RED")
	{
		_Odynummer = 21;
	}
	else if (_Odywoord=="RER")
	{
		_Odynummer = 22;
		
	}
	else if (_Odywoord=="REM")
	{
		_Odynummer = 23;
		
	}
	else if (_Odywoord=="REF")
	{
		_Odynummer = 24;
		
	}
	if (_Odywoord== "RID")
	{
		_Odynummer = 25;
		
	}
	else if (_Odywoord=="RIR")
	{
		_Odynummer = 26;
		
	}
	else if (_Odywoord=="RIM")
	{
		_Odynummer = 27;
		
	}
	else if (_Odywoord=="RIF")
	{
		_Odynummer = 28;
		
	}
	else if (_Odywoord== "RAD")
	{
		_Odynummer = 29;
		
	}
	else if (_Odywoord=="RAR")
	{
		_Odynummer = 30;
		
	}
	else if (_Odywoord=="RAM")
	{
		_Odynummer = 31;
		
	}
	else if (_Odywoord=="RAF")
	{
		_Odynummer = 32;
		
	}
	else if (_Odywoord== "MOD")
	{
		_Odynummer = 33;
	}
	else if (_Odywoord=="MOR")
	{
		_Odynummer = 34;
	}
	else if (_Odywoord=="MOM")
	{
		_Odynummer = 35;
	}
	else if (_Odywoord=="MOF")
	{
		_Odynummer = 36;
	}
	else if (_Odywoord== "MED")
	{
		_Odynummer = 37;
	}
	else if (_Odywoord=="MER")
	{
		_Odynummer = 38;
	}
	else if (_Odywoord=="MEM")
	{
		_Odynummer = 39;
	}
	else if (_Odywoord=="MEF")
	{
		_Odynummer = 40;
	}
	else if (_Odywoord== "MID")
	{
		_Odynummer = 41;
	}
	else if (_Odywoord=="MIR")
	{
		_Odynummer = 42;
	}
	else if (_Odywoord=="MIM")
	{
		_Odynummer = 43;
	}
	else if (_Odywoord=="MIF")
	{
		_Odynummer = 44;
	}
	else if (_Odywoord== "MAD")
	{
		_Odynummer = 45;
	}
	else if (_Odywoord=="MAR")
	{
		_Odynummer = 46;
	}
	else if (_Odywoord=="MAM")
	{
		_Odynummer = 47;
	}
	else if (_Odywoord=="MAF")
	{
		_Odynummer = 48;
	}
	else if (_Odywoord== "FOD")
	{
		_Odynummer = 49;
	}
	else if (_Odywoord=="FOR")
	{
		_Odynummer = 50;
	}
	else if (_Odywoord=="FOM")
	{
		_Odynummer = 51;
	}
	else if (_Odywoord=="FOF")
	{
		_Odynummer = 52;
	}
	else if (_Odywoord== "FED")
	{
		_Odynummer = 53;
	}
	else if (_Odywoord=="FER")
	{
		_Odynummer = 54;
	}
	else if (_Odywoord=="FEM")
	{
		_Odynummer = 55;
	}
	else if (_Odywoord=="FEF")
	{
		_Odynummer = 56;
	}
	else if (_Odywoord== "FID")
	{
		_Odynummer = 57;
	}
	else if (_Odywoord=="FIR")
	{
		_Odynummer = 58;
	}
	else if (_Odywoord=="FIM")
	{
		_Odynummer = 59;
	}
	else if (_Odywoord=="FIF")
	{
		_Odynummer = 60;
	}
	else if (_Odywoord== "FAD")
	{
		_Odynummer = 61;
	}
	else if (_Odywoord=="FAR")
	{
		_Odynummer = 62;
	}
	else if (_Odywoord=="FAM")
	{
		_Odynummer = 63;
	}
	else if (_Odywoord=="FAF")
	{
		_Odynummer = 64;
	}
	Odynummer = _Odynummer;
	return _Odynummer;
	*/
}
