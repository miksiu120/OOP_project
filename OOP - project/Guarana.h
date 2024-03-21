#pragma once

#include "Plant.h"
#include "World.h"
class Guarana :public Plant {

	const int SPAWN_RATIO = 5;
public:
	Guarana(World&, int, int);
	void collision(Organism*) override;
};


