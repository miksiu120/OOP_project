#include "Antylope.h"
#include "World.h"

Antylope::Antylope(World& ourWorld, int posX, int posY)
	:Animal{ ourWorld,4,4,posX,posY,'T',"Antylopa"}
{

}

void Antylope::action()
{
	Animal::action();
	Animal::action();
}

void Antylope::collision(Organism* attacker)
{
	if (attacker == nullptr or this == nullptr)
	{
		return;
	}
	Animal* animal = dynamic_cast<Animal*>(attacker);
	tryCopulate(animal);
	if (rand() % 2)
	{
		Organism::collision(attacker);
	}
	else {
		Coordinates newCords = this->getEmptyNeighbour();
		if (newCords.x != -1 and newCords.y != -1)
		{
			this->setPosition(newCords);
		}
	}
}