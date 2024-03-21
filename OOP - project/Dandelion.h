#pragma once

#include "Plant.h"
#include "World.h"
class Dandelion :public Plant {

	const int SPAWN_RATIO = 15;
public:
	Dandelion(World&, int, int);
	void action();
};

