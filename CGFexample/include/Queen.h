#pragma once
#include "Piece.h"

#define BUFFER_OFFSET(x)((char *)NULL+(x))

#include "CGFobject.h"

class Queen : public Piece
{
protected:
	GLuint vinx;
	GLuint vbo;
public:
	Queen(int x,int y, int player);
	void init();
	void draw();
	void drawQueen(GLuint, GLuint);
	int getPos(int pos);
private:
	int x,y,player,xpos,ypos;
	string type;
	CGFappearance * text;
};