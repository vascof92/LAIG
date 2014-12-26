#pragma once

#include <cmath>
#include <string>
#include "CGFapplication.h"
#include "CGFAppearance.h"
#define BUFFER_OFFSET(x)((char *)NULL+(x))
class Chairp2
{

protected:
	GLuint vinx;
	GLuint vbo;
private:
	CGFappearance * appe;
public:
	Chairp2();
	void init();
	void Drawp2(GLuint, GLuint);
	void Draw();

};