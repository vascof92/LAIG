#include <gl/glew.h>
#include "Queen.h"
#include "rainhamesh.h"
Queen::Queen(int x,int y,int player):Piece(x,y){
actanim = false;
	anim = NULL;
	this->x=x;
	this->y=y;
	this->player = player;
	this->type = "Queen";
		text = new CGFappearance();
	if(player==1){
		text->setTexture("queen1.bmp");
	}
	else
		text->setTexture("queen2.bmp");
	init();

}

int Queen::getPos(int pos){
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

void Queen::draw(){
	xpos= getPos(x);
	ypos = getPos(y);
	text->apply();
		glPushMatrix();
	glTranslatef(xpos,2.5,ypos);
		glRotatef(-90,1,0,0);
		if(player==2)
		glRotatef(180,0,0,1);
		glScalef(0.009,0.009,0.009);
		
		drawQueen(vbo, vinx);
	glPopMatrix();
}

void Queen::init() {
		glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof (struct vertex_struct) * vertex_countQueen[0], verticesQueen, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vinx);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vinx);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (indexesQueen[0]) * faces_countQueen[0] * 3, indexesQueen, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Queen::drawQueen(GLuint _vbo, GLuint _inx) {
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _inx);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(0));

  glEnableClientState(GL_NORMAL_ARRAY);
  glNormalPointer(GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(3 * sizeof (float)));

  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glTexCoordPointer(2, GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(6 * sizeof (float)));

  glDrawElements(GL_TRIANGLES, faces_countQueen[0] * 3, INX_TYPE, BUFFER_OFFSET(0));

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}