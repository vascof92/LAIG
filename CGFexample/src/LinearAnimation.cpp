#include "LinearAnimation.h"
#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <math.h>
#include <vector>
LinearAnimation::LinearAnimation(string id, float span,vector<vector<float>>controlpoints ):Animation(id,span)
{
	this->id = id;
	this->span = span*1000;
	this->controlpoints = controlpoints;
	this->currentline = 0;
	this->nlines = controlpoints.size() - 1;
	
	this->x = 0;
	this->y = 0;
	this->z = 0;
	
	this->rx = 0;
	this->ry = 0;
	this->rz = 0;
	this->ang = 0;
	this->lasttime = 0;
	this->iterationtime = 0;
	this->start=false;
	this->end = false;
	vector<float> point1 = controlpoints[currentline];
	vector<float> point2 = controlpoints[currentline+1];
	this->dx = point1[0];
	this->dy = point1[1];
	this->dz = point1[2];

	calculateVector(point1, point2);
	//setAngle(currentline);
	calculateSpans();
	
}


LinearAnimation::~LinearAnimation(void)
{
}
void LinearAnimation::update(unsigned long t){

	this->lasttime= this->time;
	this->time = t;	
	this->iterationtime = this->time - this->lasttime;	

	if(start){
		if (this->span >= -1){
			if (checkline(currentline)){			
				currentline++;
				
				if(currentline < nlines){	
					setAngle(currentline);
					vector<float> point1 = controlpoints[currentline];
					vector<float> point2 = controlpoints[currentline+1];				
					calculateVector(point1, point2);					

				}else{
					end= true;					
				}
			}
			if(!end){
				this->span -= this->iterationtime;				
				dx += (x *this->iterationtime)/ linespan[currentline];
				dy += (y *this->iterationtime)/ linespan[currentline];
				dz += (z *this->iterationtime)/ linespan[currentline];				
			}
		}
	}else{
		start=true;
	}
}

void LinearAnimation::apply(){
	
	while(ang >= 360){
		ang-=360;
	}
	glTranslatef(dx, dy, dz);
	//glRotatef(ang,0,1,0);
	
}

bool LinearAnimation::checkline(int line){
	if(line == nlines){		
		return false;
	}
	float nx,ny,nz;
	nx = controlpoints[line+1][0];
	ny = controlpoints[line+1][1];
	nz = controlpoints[line+1][2];

	bool checkx= false, checky = false, checkz=false;
	if(x<0){
		if(nx>=dx){
			checkx = true;
		}
	}else{
		if(nx<=dx){
			checkx = true;
		}
	}

	if(y<0){
		if(ny>=dy){
			checky = true;
		}
	}else{
		if(ny<=dy){
			checky = true;
		}
	}
	
	if(z<0){
		if(nz>=dz){
			checkz = true;
		}
	}else{
		if(nz<=dz){
			checkz = true;
		}
	}

	if(checkz && checky && checkx){
		return true;
	}else{
		return false;
	}

}

void LinearAnimation::calculateVector(vector<float> p1, vector<float> p2){

	x = p2[0] - p1[0];
	
	y = p2[1] - p1[1];
	
	z = p2[2] - p1[2];
	
	
}

void LinearAnimation::calculateSpans(){
	float totaldist=0;
	vector<float> linedist;	
	
	for(int i=0; i<this->nlines;i++){
		linedist.push_back(sqrt(pow(controlpoints[i+1][0]- controlpoints[i][0],2)+ pow(controlpoints[i+1][1]- controlpoints[i][1],2)+ pow(controlpoints[i+1][2]- controlpoints[i][2],2)));
		totaldist+=linedist[i];
	}
	for(int i=0; i<nlines;i++){
		linespan.push_back((linedist[i]/totaldist)*span);
	}
}

void LinearAnimation::setAngle(int line){

	float x1,x2,y1,y2;
	if(line >0){
	x1 = controlpoints[line][0]-controlpoints[line-1][0];
	y1 = controlpoints[line][1]-controlpoints[line-1][1];
	}else{
		x1 =0;
		y1=0;

	}
		
	x2 = controlpoints[line+1][0]-controlpoints[line][0];
	y2 = controlpoints[line+1][1]-controlpoints[line][1];
	float ang2;
	ang2 = acos((x1*x2 + y1*y2)/((sqrt(x1*x1+y1*y1))*sqrt(x2*x2 + y2*y2)));

	
	ang += ang2 * 180/M_PI;
	printf("%f\n",ang);	

}