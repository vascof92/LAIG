#pragma once
#include "Piece.h"

#define BUFFER_OFFSET(x)((char *)NULL+(x))

#include "CGFobject.h"

class King : public Piece
{
protected:
	GLuint vinx;
	GLuint vbo;
public:
	King(int x,int y, int player);
	void init();
	void draw();
	void drawKing(GLuint, GLuint);
	int getPos(int pos);
private:
	int x,y,player,xpos,ypos;
	string type;
	CGFappearance * text;
};