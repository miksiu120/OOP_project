#pragma once
#include "Animal.h"
class Wolf:public Animal {
	
public:
	Wolf(World&, int,int);

};

inline Wolf::Wolf(World& ourWorld, int posX, int posY)
	:Animal{ourWorld,9,5,posX,posY,'W',"Wilk"}
{

}
