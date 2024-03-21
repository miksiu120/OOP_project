#pragma once
#include "Animal.h"
class Fox :public Animal {


public:
	Fox(World&, int, int);
	void action(Organism*);
	bool doesHaveMoreStrength(Organism* other);
};

