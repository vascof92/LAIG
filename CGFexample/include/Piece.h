#pragma once

#include <cmath>
#include <string>
#include "CGFapplication.h"
#include "CGFAppearance.h"
#include "LinearAnimation.h"

class Piece 
{

public:
	Piece(int x, int y);
	virtual void draw();
	virtual void init();
	LinearAnimation * anim;
	 bool actanim;
	 int player;
	 string type;
	 void setPos(int xn,int yn);
protected:
	int getPos(int pos);
	int xpos,ypos,x,y;
	 
};



/*
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

*/