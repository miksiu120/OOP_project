#pragma once
#include "Plant.h"
class Grass :public Plant {

   
public:
	Grass(World&, int, int);
	void action();
};



