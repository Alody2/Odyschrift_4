/* 
This library is part of the Odyschrift project. It has been originally created by Alle v Meeteren and modified by Jurre Ongering on 
15 March 2020
This module of the project enables physically handicapped people to play a game of "connect-four". A joystick is used as a controller. 
We use an Arduino Mega
*/
#ifndef OdyVierOpRij_h
#define OdyVierOpRij_h
class OdyVierOpRij
{ 
public:
OdyVierOpRij(int mDO, int mDE, int mDI,int mDA,int mRO,int mRE,int mRI,int mRA);
	void  actie(String Odywoord); 
private:
	int _mDO;
	int _mDE;
	int _mDI;
	int _mDA;
	int _mRO;
	int _mRE;
	int _mRI;
	int _mRA;
	int _turntime;             
};
#endif
