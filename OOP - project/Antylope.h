#pragma once
#include "Animal.h"

class Antylope :public Animal {


public:
	Antylope(World&, int, int);
	void action() override;
	void collision(Organism*) override;
};

