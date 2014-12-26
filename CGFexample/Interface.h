#pragma once

#include "CGFinterface.h"
#include "Scene.h"
#include "LinearAnimation.h"


class Interface : public CGFinterface
{
private:
	Scene * scenee;
public:
	virtual void processMouse(int button, int state, int x, int y);	
	void performPicking(int x, int y);
	void processHits(GLint hits, GLuint buffer[]); 
};