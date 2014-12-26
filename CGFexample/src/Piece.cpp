#include "Piece.h"
using namespace std;

Piece::Piece(int x, int y)
{
	this->x=x;
	this->y = y;
	type = "";
	player = 0;
	anim = NULL;

}

void Piece::init(){}


int Piece::getPos(int pos){
	switch (pos)
	{
	default:
		break;
	case 1 :
		return 0;
	case 2:
		return 2;
	case 3:
		return 4;
	case 4:
		return 6;
	case 5:
		return 8;
	case 6:
		return 10;
	case 7:
		return 12;
	case 8:
		return 14;
	}

	
}

void Piece::setPos(int xn,int yn){
	
	x=xn;
	y=yn;
}

void Piece::draw(){

	xpos = getPos(x);
	ypos = getPos(y);

	
	glPushMatrix();

		glTranslatef(xpos,0.1,ypos);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3d(0,0,0);
		glTexCoord2d(1,0);
		glVertex3d(2,0,0);
		glTexCoord2d(1,1);
		glVertex3d(2,0,2);
		glTexCoord2d(0,1);
		glVertex3d(0,0,2);
		

	glEnd();
	glPopMatrix();

}


/*
Piece::Piece()
{
	type = "";
	player = 0;

}

Piece::Piece(string t, int p){
	type = t;
	player = p;
	color = new CGFappearance();
	if(p ==1){
		GLfloat ambientw[] = { 0, 0, 0, 1.0 };
		GLfloat diffusew[] = { 0.55, 0.55, 0.55, 1.0 };
		GLfloat specularw[] = { 0.7, 0.7, 0.7, 1.0 };
		color->setAmbient(ambientw);
		color->setDiffuse(diffusew);
		color->setSpecular(specularw);
		color->setShininess(0.25);
	}else if(p==2){

		GLfloat ambientb[] = { 0, 0, 0, 1.0 };
		GLfloat diffuseb[] = { 0.01, 0.01, 0.01, 1.0 };
		GLfloat specularb[] = { 0.5, 0.5, 0.5, 1.0 };
		color->setAmbient(ambientb);
		color->setDiffuse(diffuseb);
		color->setSpecular(specularb);
		color->setShininess(0.25);
	}

}

void Piece::draw(){


	if(player!=0){
		glPushMatrix();
		color->apply();
		glTranslatef(-0.5,0,0.5);
		glRotatef(-90,1,0,0);

		glPushMatrix();
		GLUquadric *cilindro = gluNewQuadric();
		gluQuadricNormals(cilindro, GLU_SMOOTH); 
		gluQuadricTexture(cilindro, true);
		gluCylinder(cilindro, 0.5, 0.5, 0.3, 10, 10);
		glRotatef(180, 1, 0, 0);
		gluDisk(cilindro, 0, 0.5, 10, 1);
		glRotatef(180, 1, 0, 0);
		glTranslatef(0, 0, 0.3);
		gluDisk(cilindro, 0, 0.5, 10, 1);
		glTranslatef(0, 0, -0.3);
		gluDeleteQuadric(cilindro);
		glPopMatrix();
		glPopMatrix();
	}

}

string Piece::getType(){

	return type;

}
int Piece::getPlayer(){

	return player;

}
void Piece::setType(string t){
	type= t;
}
void Piece::setPlayer(int p){

	player = p;

}
*/