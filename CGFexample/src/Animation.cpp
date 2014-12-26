#include "Animation.h"


Animation::Animation(string id,float span)
{
	this->id= id;
	this->span= span*1000;
	end = false;
}


Animation::~Animation(void)
{
}

string Animation::getID(){
	return this->id;
}
