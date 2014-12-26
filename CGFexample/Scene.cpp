#include <math.h>
#include <iostream>
#include "Scene.h"
#include <typeinfo>



void Scene::init()
{
	//limpa a cor activa debackground e define nova cor RGBA
	glEnable(GL_LIGHTING);

	 GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  // glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
	  // Define ambient light

	
glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

glShadeModel(GL_SMOOTH);
	float light0_pos[4] = {4.0, 6.0, 5.0, 1.0};
	light0 = new CGFlight(GL_LIGHT1, light0_pos);
	light0->enable();
	board = new Board();
	boardtex = new CGFappearance();
	boardtex->setTexture("board.png");
	glTexParameteri( GL_TEXTURE_2D, 
                 GL_TEXTURE_WRAP_S, 
		 GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, 
                 GL_TEXTURE_WRAP_T, 
		 GL_REPEAT );
	textFloor = new CGFappearance("floor.jpg",5,5);
	textWall = new CGFappearance("walltext.jpg",1,1);
	emo = new CGFappearance();

	floor = new Rectangle(0,1,0,1);
	wall = new Rectangle(0,1,0,1);
	cadeira = new Chair();



	matrix[0][0] = new Rook(1,1,1);
	matrix[0][1] = new Knight(2,1,1);
	matrix[0][2] = new Bishop(3,1,1);
	matrix[0][3] = new King(4,1,1);
	matrix[0][4] = new Queen(5,1,1);
	matrix[0][5] = new Bishop(6,1,1);
	matrix[0][6] = new Knight(7,1,1);
	matrix[0][7] = new Rook(8,1,1);
	matrix[1][0] = new Pawn(1,2,1);
	matrix[1][1] = new Pawn(2,2,1);
	matrix[1][2] = new Pawn(3,2,1);
	matrix[1][3] = new Pawn(4,2,1);
	matrix[1][4] = new Pawn(5,2,1);
	matrix[1][5] = new Pawn(6,2,1);
	matrix[1][6] = new Pawn(7,2,1);
	matrix[1][7] = new Pawn(8,2,1);
	
	matrix[7][0] = new Rook(1,8,2);
	matrix[7][1] = new Knight(2,8,2);
	matrix[7][2] = new Bishop(3,8,2);
	matrix[7][3] = new King(4,8,2);
	matrix[7][4] = new Queen(5,8,2);
	matrix[7][5] = new Bishop(6,8,2);
	matrix[7][6] = new Knight(7,8,2);
	matrix[7][7] = new Rook(8,8,2);
	matrix[6][0] = new Pawn(1,7,2);
	matrix[6][1] = new Pawn(2,7,2);
	matrix[6][2] = new Pawn(3,7,2);
	matrix[6][3] = new Pawn(4,7,2);
	matrix[6][4] = new Pawn(5,7,2);
	matrix[6][5] = new Pawn(6,7,2);
	matrix[6][6] = new Pawn(7,7,2);
	matrix[6][7] = new Pawn(8,7,2);
	
	for(int y = 2; y<6;y++){

		for(int x= 0; x<8;x++){
			matrix[y][x] = NULL;

		}
	}
	

	
	mesa = new Table();

		unsigned long updatePeriod=50;
	this->setUpdatePeriod(updatePeriod);
	// Defines a default normal
	glNormal3f(0, 0, 1);

}


void Scene::display() 
{

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw (and update) light
	light0->draw();
	//piece->draw();

	// Draw axis
	axis.draw();
	boardtex->apply();
	board->draw();
	// ---- END Background, camera and axis setup


	// ---- BEGIN feature demos
	glPushMatrix();
	glPushName(-1);		// Load a default name	
	glPopMatrix();
	for (int y=0; y < 8; y++)
	{
		glPushMatrix();
		glTranslatef(0, 0, y);
		glLoadName(y);
		for (int x=0; x < 8; x++)
		{
			glPushName(x);
			if(matrix[y][x]!=NULL)
				
			matrix[y][x]->draw();
			glPopName();
	
		}
		glPopMatrix();
	}
	
	
				
		
	mesa->draw();
	glPushMatrix();
	glTranslatef(-60,-26,84);
	glScalef(150,1,150);
	glRotatef(-90,1,0,0);
	textFloor->apply();
	floor->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60,-26,-66);
	glScalef(150,150,1);
	textWall->apply();
	wall->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60,-26,84);
	glScalef(1,150,150);
	glRotatef(90,0,1,0);
	textWall->apply();
	wall->draw();
	glPopMatrix();

	//cadeira1
	glPushMatrix();
	glTranslatef(17.3,-12.4,-27.8);
	glRotatef(90,0,1,0);
	glScalef(0.8,0.8,0.8);
	cadeira->Draw();
	glPopMatrix();

	//cadeira2
	glPushMatrix();

	glTranslatef(-2,-12.4,48.8);
	glRotatef(-90,0,1,0);
	glScalef(0.8,0.8,0.8);

	cadeira->Draw();
	glPopMatrix();

	// scale down a bit	
	

	// picking example, the important parts are the gl*Name functions
	// and the code in the associted PickInterface class

	
	

	// ---- END feature demos

	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();


}

void Scene::addAnimation(Animation* animation)
{
	animations.push_back(animation);

}

Piece * Scene::getMatrix(int x, int y){
	
	return  matrix[y][x];
}

void Scene::update(unsigned long t){

	

	std::vector<Animation *>::iterator it = animations.begin();
	for(it;it!=animations.end();it++){
		
		(*it)->update(t);
	}

}