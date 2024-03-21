#pragma once
#include "Animal.h"
class Sheep :public Animal {


public:
	Sheep(World& , int, int);
};

inline Sheep::Sheep(World& ourWorld, int posX, int posY)
	:Animal{ourWorld,4,4,posX,posY,'S',"Owca"}
{

}