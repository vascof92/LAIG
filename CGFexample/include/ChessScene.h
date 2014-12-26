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

class ChessScene : public CGFscene
{
public:
	ChessScene();
	void init();
	void display();
	void movepiece(int x1, int y1, int x2, int y2);
		void update(unsigned long t);
	void addAnimation(Animation* animation);
	Piece * getMatrix(int x, int y);

private:
	CGFlight* light0;
	Board* board;
	CGFappearance* boardtex;
	CGFappearance* piecetex;
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