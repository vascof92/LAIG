#include "Board.h"


void Board::draw() 
{

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3d(0,0,0);
		glTexCoord2d(1,0);
		glVertex3d(0,0,8);
		glTexCoord2d(1,1);
		glVertex3d(8,0,8);
		glTexCoord2d(0,1);
		glVertex3d(8,0,0);

	glEnd();
}