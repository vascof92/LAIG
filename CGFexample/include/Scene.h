#pragma once
#include "CGFscene.h"
#include "CGFshader.h"
#include "Board.h"
#include "Piece.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include <string>


#include <map>

class Scene : public CGFscene
{
public:
	void init();
	void display();
	

private:
	CGFlight* light0;
	Board* board;
	CGFappearance* boardtex;
	CGFappearance* emo;
	Piece* piece;
	Piece* matrix[8][8];

};