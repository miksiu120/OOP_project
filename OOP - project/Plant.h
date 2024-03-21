#pragma once
#include "Organism.h"
#include "Animal.h"
class Plant: public Organism
{
protected:
	const int SPAWN_RATIO;
public:
	Plant(World&, int, int, int, char, int spawnRatio = 5,std::string name="Roslina");
	bool doesSpread(int);
	virtual void action();
	int getSpawnRatio();
};


