#pragma once
#include "Piece.h"

#define BUFFER_OFFSET(x)((char *)NULL+(x))

#include "CGFobject.h"

class Pawn : public Piece
{
protected:
	GLuint vinx;
	GLuint vbo;
public:
	Pawn(int x,int y, int player);
	void init();
	void draw();
	void drawPawn(GLuint, GLuint);
	int getPosX(int pos);
	int getPosY(int pos);
	void setPos(int xn,int yn);
private:
	int x,y,player,xpos,ypos;
	string type;
	CGFappearance * text;
};