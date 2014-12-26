#include <gl/glew.h>
#include "Chair2.h"
#include "chair\chairmesh2.h"


Chairp2::Chairp2(){

	appe = new CGFappearance();
	appe->setTexture("leather.jpg");
	init();
}

void Chairp2::Draw(){
	appe->apply();
	glPushMatrix();
	glTranslatef(-1,6,-11.2);
		Drawp2(vbo, vinx);
	glPopMatrix();
}

void Chairp2::init(){
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof (struct vertex_struct) * vertex_countP2[0], verticesP2, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vinx);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vinx);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (indexesP2[0]) * faces_countP2[0] * 3, indexesP2, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Chairp2::Drawp2(GLuint _vbo, GLuint _inx){
	  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _inx);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(0));

  glEnableClientState(GL_NORMAL_ARRAY);
  glNormalPointer(GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(3 * sizeof (float)));

  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glTexCoordPointer(2, GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(6 * sizeof (float)));

  glDrawElements(GL_TRIANGLES, faces_countP2[0] * 3, INX_TYPE, BUFFER_OFFSET(0));

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}
