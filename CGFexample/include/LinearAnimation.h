#pragma once

#include"Animation.h"

class LinearAnimation: public Animation
{
private:
	vector<vector<float>> controlpoints;
	int currentline;
	vector<float> linespan;
	int nlines;
	float x, y, z; //vector coords
	float dx, dy, dz; //translate coords
	float rx,ry,rz; //rotate coords
	unsigned int lasttime;
	float ang;
	unsigned int iterationtime;
	bool start;
	bool end;
public:
	LinearAnimation(string id, float span,vector<vector<float>>controlpoints );
	void update(unsigned long t);
	void apply();
	~LinearAnimation(void);
	void calculateVector(vector<float> p1, vector<float> p2);
	bool checkline(int line);
	void calculateSpans();
	void setAngle(int line);
};

