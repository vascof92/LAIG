#pragma once
#include "Piece.h"

#define BUFFER_OFFSET(x)((char *)NULL+(x))

#include "CGFobject.h"

class Knight : public Piece
{
protected:
	GLuint vinx;
	GLuint vbo;
public:
	Knight(int x,int y, int player);
	void init();
	void draw();
	void drawKnight(GLuint, GLuint);
	int getPos(int pos);
private:
	int x,y,player,xpos,ypos;
	string type;
	CGFappearance * text;
};