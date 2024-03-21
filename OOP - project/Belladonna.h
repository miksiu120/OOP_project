#pragma once
#include "Plant.h"
#include "World.h"
class Belladonna :public Plant {

	const int SPAWN_RATIO = 10;
public:
	Belladonna(World&, int, int);

};

inline  Belladonna::Belladonna(World& ourWorld, int posX, int posY)
	:Plant{ourWorld,99,posX,posY,'B',3,"Wilcza jagoda"}
{

}
