#pragma once
#include "Piece.h"


#define BUFFER_OFFSET(x)((char *)NULL+(x))

#include "CGFobject.h"

class Bishop : public Piece
{
protected:
	GLuint vinx;
	GLuint vbo;
public:
	Bishop(int x,int y, int player);
	void init();
	void draw();
	void drawBishop(GLuint, GLuint);
	int getPos(int pos);
private:
	int x,y,player,xpos,ypos;
	string type;
	CGFappearance *text;
};