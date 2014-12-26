#pragma once

#include <cmath>
#include <string>
#include "Chair1.h"
#include "Chair2.h"
#include "Chair3.h"
#include "CGFapplication.h"
#include "CGFAppearance.h"


class Chair
{
	private:
	Chairp1 * part1;
	Chairp2 * part2;
	Chairp3 * part3;
	
public:
	Chair();
	void Draw();


};