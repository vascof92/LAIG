#include <gl/glew.h>
#include "Pawn.h"
#include "peaomesh.h"
Pawn::Pawn(int x,int y,int player):Piece(x,y){
	actanim = false;
	anim = NULL;
	this->x=x;
	this->y=y;
	this->player = player;
	this->type = "Pawn";

	text = new CGFappearance();
	if(player==1){
		text->setTexture("pawn1.bmp");
	}
	else
		text->setTexture("pawn2.bmp");
	init();

}

void Pawn::setPos(int xn,int yn){

	x=xn;
	y=yn;
}

int Pawn::getPosX(int pos){
	switch (pos)
	{
	default:
		break;
	case 1 :
		return 1;
	case 2:
		return 3;
	case 3:
		return 5;
	case 4:
		return 7;
	case 5:
		return 9;
	case 6:
		return 11;
	case 7:
		return 13;
	case 8:
		return 15;
	}
}


void Pawn::draw(){
	x = Piece::x;
	y = Piece::y;
	xpos = getPosX(x);
	ypos = getPosX(y);
	

	text->apply();
		glPushMatrix();
	glTranslatef(xpos,1,ypos);
		glRotated(-90,1,0,0);
		glScalef(0.009,0.009,0.009);
		
		drawPawn(vbo, vinx);
	glPopMatrix();
}

void Pawn::init() {
		glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof (struct vertex_struct) * vertex_countPawn[0], verticesPawn, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vinx);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vinx);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (indexesPawn[0]) * faces_countPawn[0] * 3, indexesPawn, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Pawn::drawPawn(GLuint _vbo, GLuint _inx) {
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _inx);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(0));

  glEnableClientState(GL_NORMAL_ARRAY);
  glNormalPointer(GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(3 * sizeof (float)));

  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glTexCoordPointer(2, GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(6 * sizeof (float)));

  glDrawElements(GL_TRIANGLES, faces_countPawn[0] * 3, INX_TYPE, BUFFER_OFFSET(0));

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}