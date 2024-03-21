#include "Plant.h"
#include "World.h"

Plant::Plant(World& ourWorld, int strength, int x, int y, char sign, int spawnRatio,std::string name)
	:Organism{ ourWorld,strength,0,x,y,sign,name}, SPAWN_RATIO{spawnRatio}
{

}

 bool Plant::doesSpread(int chanceToSpread)
{
	int result = rand() % 100;
	if (result < chanceToSpread)
		return true;
	else
		return false;
}



 void Plant::action()
{
	if (doesSpread(SPAWN_RATIO))
	{
		Coordinates moveTo = getRandomNeighbour();
		Coordinates newCoords{ getX() + moveTo.x,getY() + moveTo.y };
		if (canMove(newCoords)
			and ourWorld.getFromPostion(newCoords) == nullptr)
		{
			Plant* newPlant = new Plant{*this};
			newPlant->setPosition(newCoords);
			newPlant->setAge(0);
			ourWorld.addNewElementToWorld(newPlant);
		}
	}
}
 int Plant::getSpawnRatio() {
	 return SPAWN_RATIO;
 }
