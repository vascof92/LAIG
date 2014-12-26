
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
	glShadeModel(GL_SMOOTH);


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

		for(int x= 0; x<9;x++){
			matrix[y][x] = new Piece(x+1,y+1);

		}
	}

	mesa = new Table();

	unsigned long updatePeriod=50;
	this->setUpdatePeriod(updatePeriod);
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

		glLoadName(y);
		for (int x=0; x < 8; x++)
		{
			glPushMatrix();
			glPushName(x);
			if(matrix[y][x]->anim!=NULL)
				matrix[y][x]->anim->apply();

			matrix[y][x]->draw();

			glPopName();
			glPopMatrix();
		}

		glPopMatrix();
	}



	/*	
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
	*/
	// scale down a bit	


	// picking example, the important parts are the gl*Name functions
	// and the code in the associted PickInterface class




	// ---- END feature demos

	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();


}



void ChessScene::movepiece(int y1, int x1, int y2, int x2){

	vector<vector<float>> controlpoints;

	vector<float> point1;
	point1.push_back(0);
	point1.push_back(0);
	point1.push_back(0);

	controlpoints.push_back(point1);
	vector<float> point2;
	point2.push_back(0);
	point2.push_back(3);
	point2.push_back(0);

	controlpoints.push_back(point2);
	vector<float> point3;
	point3.push_back(2*(x2-x1));
	point3.push_back(3);
	point3.push_back(2*(y2-y1));

	controlpoints.push_back(point3);


	vector<float> point4;
	point4.push_back(2*(x2-x1));
	point4.push_back(0);
	point4.push_back(2*(y2-y1));

	controlpoints.push_back(point4);
	//controlpoints.push_back(point4);

	matrix[y1][x1]->anim = new LinearAnimation("1",3,controlpoints);
	addAnimation(matrix[y1][x1]->anim);
	matrix[y1][x1]->actanim = true;



	matrix[y2][x2] = matrix[y1][x1];
	matrix[y2][x2]->setPos(x2+1,y2+1);

	matrix[y1][x1]= new Piece(x1+1,y1+1);




}



void ChessScene::addAnimation(Animation* animation)
{
	animations.push_back(animation);

}

Piece * ChessScene::getMatrix(int x, int y){

	return  matrix[y][x];
}

void ChessScene::update(unsigned long t){



	std::vector<Animation *>::iterator it = animations.begin();
	for(it;it!=animations.end();it++){

		(*it)->update(t);
	}

}