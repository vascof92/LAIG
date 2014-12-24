#pragma once
#include "CGFscene.h"
#include "CGFshader.h"
#include "Board.h"
#include "Piece.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include <string>


#include <map>

class ChessScene : public CGFscene
{
public:
	ChessScene();
	void init();
	void display();
	void movepiece(int x1, int y1, int x2, int y2);


private:
	CGFlight* light0;
	Board* board;
	CGFappearance* boardtex;
	CGFappearance* piecetex;
	Piece* piece;
	Piece* matrix[8][8];

};