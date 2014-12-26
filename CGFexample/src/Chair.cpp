
#include "Chair.h"


Chair::Chair(){

	part1 = new Chairp1();
	part2 = new Chairp2();
	part3 = new Chairp3();
}

void Chair::Draw(){
	part1->Draw();
	part2->Draw();
	part3->Draw();
}

