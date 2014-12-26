#pragma once

#include <cmath>
#include <string>
#include "CGFapplication.h"
#include "CGFAppearance.h"

#define BUFFER_OFFSET(x)((char *)NULL+(x))

class Chairp1
{
	protected:
	GLuint vinx;
	GLuint vbo;
private:
	CGFappearance * appe;
public:
	Chairp1();
	void init();
	void Drawp1(GLuint, GLuint);
	void Draw();
};
