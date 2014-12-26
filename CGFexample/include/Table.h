#pragma once

#define BUFFER_OFFSET(x)((char *)NULL+(x))
#include <cmath>
#include <string>
#include "CGFapplication.h"
#include "CGFAppearance.h"
#include "CGFobject.h"

class Table
{
protected:
	GLuint vinx;
	GLuint vbo;
public:
	Table();
	void init();
	void draw();
	void drawTable(GLuint, GLuint);
	
private:
	CGFappearance * text;
};