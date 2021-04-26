/*
  OdyAlgemeen.h - Library for flashing OdyAlgemeen code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef OdyAlgemeen_h
#define OdyAlgemeen_h

#include "Arduino.h"

class OdyAlgemeen
{
  public:
    OdyAlgemeen();
    String Odywoord;
    int Odynummer;
    int NaarNummer(String Odywoord);
	void OdyAlgemeen::regeltModule(int odyModule);
  private:
    int _Odynummer;
};

#endif
