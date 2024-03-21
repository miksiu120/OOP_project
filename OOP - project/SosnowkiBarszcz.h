#pragma once
#include "Plant.h"
#include "World.h"
class SosnowskiBarszcz :public Plant {

	const int SPAWN_RATIO = 57;

public:
	SosnowskiBarszcz(World& , int, int);
	void action() override;
};


