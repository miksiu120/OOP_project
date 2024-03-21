#include "Grass.h"
#include "World.h"

Grass::Grass(World& ourWorld, int posX, int posY)
	:Plant{ ourWorld,0,posX,posY,'G',7,"Trawa"}
{

}

void Grass::action()
{
	if (doesSpread(SPAWN_RATIO))
	{
		Coordinates moveTo = getRandomNeighbour();
		Coordinates newCoords{ getX() + moveTo.x,getY() + moveTo.y };
		if (canMove(newCoords) 
			and ourWorld.getFromPostion(newCoords)==nullptr)
		{
			Grass* newElement = new Grass{ ourWorld,newCoords.x,newCoords.y };
			ourWorld.addNewElementToWorld(newElement);
		}
	}

}

