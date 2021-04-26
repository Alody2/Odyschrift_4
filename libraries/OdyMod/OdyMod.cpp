/*
  OdyMod.cpp - Library to connect apps an Odyschrift input.
  Created by Alle van Meeteren, 22 april 2020. 
*/

#include "Arduino.h"
#include "OdyMod.h"
#include "OdyVierOpRij.h"

OdyMod::OdyMod(int intmodule)
{
			switch (intmodule)
			{
				case 2:
					OdyVierOpRij odyvieroprij(38,40,42,44,46,48,50,52);
				break;
			}

  _intmodule = intmodule;
}

void OdyMod::regeltModule(String odywoord)
{
	switch (odywoord.length())
	{
		case 1:
			switch (_intmodule)
			{
				case 13:
				break;
			}
		break;
		case 2:
			switch (_intmodule)
			{
				case 2:
					odyvieroprij.actie(odywoord);
				break;
			}
		break;
		case 3:
			switch (_intmodule)
			{
				case 2:
				break;
			}
		break;
		case 4:
			switch (_intmodule)
			{
				case 13:
				break;
			}
		break;
	}
}

