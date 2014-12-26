#include <gl/glew.h>
#include "Chair3.h"
#include "chair\chairmesh3.h"

Chairp3::Chairp3(){

	appe = new CGFappearance();
	appe->setTexture("woodchair.jpg");
	init();
}

void Chairp3::Draw(){
	appe->apply();
	glPushMatrix();
		Drawp3(vbo, vinx);
	glPopMatrix();
}

void Chairp3::init(){
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof (struct vertex_struct) * vertex_countP3[0], verticesP3, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vinx);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vinx);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (indexesP3[0]) * faces_countP3[0] * 3, indexesP3, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Chairp3::Drawp3(GLuint _vbo, GLuint _inx){
	  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _inx);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(0));

  glEnableClientState(GL_NORMAL_ARRAY);
  glNormalPointer(GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(3 * sizeof (float)));

  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glTexCoordPointer(2, GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(6 * sizeof (float)));

  glDrawElements(GL_TRIANGLES, faces_countP3[0] * 3, INX_TYPE, BUFFER_OFFSET(0));

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}