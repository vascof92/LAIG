#pragma once
#define BUFFER_OFFSET(x)((char *)NULL+(x))
#include <cmath>
#include <string>
#include "CGFapplication.h"
#include "CGFAppearance.h"
class Chairp3
{
protected:
	GLuint vinx;
	GLuint vbo;
private:
	CGFappearance * appe;

public:
	Chairp3();
	void init();
	void Drawp3(GLuint, GLuint);
	void Draw();
};
