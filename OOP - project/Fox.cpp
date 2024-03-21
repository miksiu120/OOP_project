#include "Fox.h"
#include "World.h"
Fox::Fox(World& ourWorld, int posX, int posY)
	:Animal{ ourWorld,3,7,posX,posY,'F',"Lis"}
{
	
}


void Fox::action(Organism* collied)
{
	Coordinates moveTo = getRandomNeighbour();
	Coordinates newCoords{ getX() + moveTo.x,getY() + moveTo.y };
	Organism* oragnismOnNewCoords = ourWorld.getFromPostion(newCoords);
	if (canMove(newCoords) and oragnismOnNewCoords == nullptr)
	{
		setX(newCoords.x);
		setY(newCoords.y);
	}
	else if(oragnismOnNewCoords != nullptr and
	oragnismOnNewCoords->getStrength()<=this->getStrength())
	{
		this->collision(oragnismOnNewCoords);
	}
}