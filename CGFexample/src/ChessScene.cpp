
#include <math.h>
#include <iostream>
#include "ChessScene.h"
#include <typeinfo>

ChessScene::ChessScene(){
	

}

void ChessScene::init()
{
	//limpa a cor activa debackground e define nova cor RGBA
	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);  // Define ambient light
	float light0_pos[4] = {4.0, 6.0, 5.0, 1.0};
	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->enable();
	board = new Board();
	boardtex = new CGFappearance();
	boardtex->setTexture("board.png");
	piecetex = new CGFappearance();
	
	
	matrix[0][0] = new Piece("",1);
	matrix[0][1] = new Piece("",1);
	matrix[0][2] = new Piece("",1);
	matrix[0][3] = new Piece("",1);
	matrix[0][4] = new Piece("",1);
	matrix[0][5] = new Piece("",1);
	matrix[0][6] = new Piece("",1);
	matrix[0][7] = new Piece("",1);
	matrix[1][0] = new Piece("",1);
	matrix[1][1] = new Piece("",1);
	matrix[1][2] = new Piece("",1);
	matrix[1][3] = new Piece("",1);
	matrix[1][4] = new Piece("",1);
	matrix[1][5] = new Piece("",1);
	matrix[1][6] = new Piece("",1);
	matrix[1][7] = new Piece("",1);

	matrix[7][0] = new Piece("",2);
	matrix[7][1] = new Piece("",2);
	matrix[7][2] = new Piece("",2);
	matrix[7][3] = new Piece("",2);
	matrix[7][4] = new Piece("",2);
	matrix[7][5] = new Piece("",2);
	matrix[7][6] = new Piece("",2);
	matrix[7][7] = new Piece("",2);
	matrix[6][0] = new Piece("",2);
	matrix[6][1] = new Piece("",2);
	matrix[6][2] = new Piece("",2);
	matrix[6][3] = new Piece("",2);
	matrix[6][4] = new Piece("",2);
	matrix[6][5] = new Piece("",2);
	matrix[6][6] = new Piece("",2);
	matrix[6][7] = new Piece("",2);
	for(int y = 2; y<6;y++){

		for(int x= 0; x<8;x++){
			matrix[y][x] = new Piece();

		}
	}
	
	
	// Defines a default normal
	glNormal3f(0, 0, 1);

}


void ChessScene::display() 
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
			glPushMatrix();
			
			glTranslatef(x,0,0);	
			glRotatef(90,0,1,0);
			glPushName(x);
			piecetex->apply();
			matrix[y][x]->draw();
			glPopName();
			glPopMatrix();
		}
		glPopMatrix();
	}

	
	
	
	// scale down a bit	
	

	// picking example, the important parts are the gl*Name functions
	// and the code in the associted PickInterface class

	
	

	// ---- END feature demos

	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();


}



void ChessScene::movepiece(int y1, int x1, int y2, int x2){

	matrix[y2][x2] = matrix[y1][x1];	

	matrix[y1][x1]= new Piece();

	printf("%d \n", matrix[y1][x1]->getPlayer());


}



