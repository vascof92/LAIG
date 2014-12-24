#pragma once

#include "CGFinterface.h"
#include "ChessScene.h"

using namespace std;
class ChessInterface : public CGFinterface
{

public:

	ChessScene *scene;
	ChessInterface(ChessScene *chess);
	virtual void processMouse(int button, int state, int x, int y);	
	void performPicking(int x, int y);
	void processHits(GLint hits, GLuint buffer[]); 
	void setScene(ChessScene *scene);
private:
	vector<map<char, int>> selectedpos;
};