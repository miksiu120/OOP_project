#include "Dandelion.h"
#include "World.h"

Dandelion::Dandelion(World& ourWorld, int posX, int posY)
	:Plant{ ourWorld,0,posX,posY,'D',5,"Mlecz"}
{

}

void Dandelion::action()
{
	for(int i=0;i<3;i++)
		Plant::action();
	
}