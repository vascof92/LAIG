#pragma once

#include "King.h"
#include "knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Rectangle.h"
#include "Bishop.h"
#include "Table.h"
#include "CGFscene.h"
#include "CGFshader.h"
#include "CGFappearance.h"
#include "Board.h"
#include "CGFaxis.h"
#include "Chair.h"

#include "CGFapplication.h"


#include <string>


#include <map>

class Scene : public CGFscene
{
public:
	void init();
	void display();
	void update(unsigned long t);
	void addAnimation(Animation* animation);
	Piece * getMatrix(int x, int y);

private:
	CGFlight* light0;
	Board* board;
	CGFappearance* boardtex;
	CGFappearance* emo;
	Piece* piece;
	Piece* matrix[8][8];
	Table * mesa;
	Rectangle * floor;
	Rectangle * wall;
	CGFappearance * textFloor;
	CGFappearance * textWall;
	Chair * cadeira;
	vector<Animation*> animations;
	vector<Piece*> pieces;

};