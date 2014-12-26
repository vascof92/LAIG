#pragma once


#include "CGFAppearance.h"
#include <cmath>
#include <stdio.h>

class Rectangle
{
private:
	float x1,x2,y1,y2;
	int dl;

public:
	Rectangle(float x1,float x2,float y1,float y2);
	void draw();
};
