#pragma once

#include <cmath>
#include <string>
#include "CGFapplication.h"

class Piece
{
public:
	Piece();
	Piece(string t, int p);
	void draw();
	string getType();
	int getPlayer();
	void setType(string t);
	void setPlayer(int p);
private:

	int player;
	string type; 
	CGFappearance* color;
};

