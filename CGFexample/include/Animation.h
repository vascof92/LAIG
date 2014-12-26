#pragma once
#include <string>
#include <vector>
#include "CGFApplication.h"

using namespace std;

class Animation
{

protected:
	long span;
	string id;
	long time;
	bool end;


public:
	Animation(string id,float span);
	string getID();
	virtual void update(unsigned long t)=0;
	virtual void apply()=0;
	~Animation(void);
};

