#pragma once
#include <iostream>
#include "Organism.h"
class WorldElement;
class Animal :public Organism
{
protected:
	void tryCopulate(Organism*);
public:
	Animal(World& ourWorld, int strengh, int initiative, int x, int y, char asciiRep,std::string name="Zwierze");
	~Animal();
	void action();
	void collision(Organism* compared) override;
	bool tryBornNewAnimal();
};


