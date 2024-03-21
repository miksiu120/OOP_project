#pragma once
#include "Animal.h"
class Turtle :public Animal {


public:
	Turtle(World& ourWorld, int, int);
	void action() override;
	void collision(Organism*) override;
};

