/*
  OdyMod.h - Library to connect apps an Odyschrift input.
  Created by Alle van Meeteren, 22 april 2020. 
*/
#ifndef OdyMod_h
#define OdyMod_h

#include "Arduino.h"
#include "OdyVierOpRij.h"

class OdyMod
{
  public:
   	OdyMod(int intmodule);
    	void regeltModule(String odywoord);
  private:
    	int _intmodule;
};

#endif
