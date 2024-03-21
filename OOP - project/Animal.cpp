#include "Animal.h"
#include "World.h"
#include <string>
#include <iostream>
Animal::Animal(World& ourWorld, int strengh, int initiative, int x, int y, char asciiRep,std::string animal)
	:Organism(ourWorld,strengh, initiative, x, y, asciiRep,animal)
{
}

Animal::~Animal()
{
}

void Animal::action()
 {
	 Coordinates moveTo = getRandomNeighbour();
	 Coordinates newCoords{ getX() + moveTo.x,getY() + moveTo.y };
	 Organism* organismOnNewCoords = ourWorld.getFromPostion(newCoords);
	
	 if (canMove(newCoords) and organismOnNewCoords == nullptr)
	 {
		// ourWorld.addNewLog(this->name+"("+ std::to_string(getX()) + "," + std::to_string(getY()) + ")"+ + " poruszyl sie do punktu ("
			// + std::to_string(newCoords.x) + "," + std::to_string(newCoords.y) + ")");
		 
		 setX(newCoords.x);
		 setY(newCoords.y);
	 }
	 else if(organismOnNewCoords !=nullptr)
	 {
		 organismOnNewCoords->collision(this);
	 }
 }

void Animal::collision(Organism* colliedElement)
{
	Organism::collision(colliedElement);

	if (colliedElement == nullptr or this == nullptr)
	{
		return;
	}
		tryCopulate(colliedElement);
}
void Animal::tryCopulate(Organism* potencialSame) {

	Animal* sameAnimal = dynamic_cast<Animal*>(potencialSame);
	if (sameAnimal == nullptr)
		return;

	if (this->getAscii() == sameAnimal->getAscii() and
		this->getAge() > 10 and sameAnimal->getAge() > 10)
	{
		if (this->tryBornNewAnimal())
			return;

		if (sameAnimal->tryBornNewAnimal())
			return;
	}
}

bool Animal::tryBornNewAnimal()
{
	Organism* newOrganism = new Animal{ *this };
	Coordinates positionOfNewElement = getEmptyNeighbour();
	if (positionOfNewElement.x != -1 and positionOfNewElement.y != -1)
	{
		newOrganism->setPosition(positionOfNewElement);
		ourWorld.addNewLog("Kopulacja " + this->name + " nowe zwierze (" + 
		std::to_string(positionOfNewElement.x) +" "+ std::to_string(positionOfNewElement.y)+")");
		newOrganism->setAge(0);
		this->setAge(3);
		ourWorld.addNewElementToWorld(newOrganism);
		return true;
	}
	else {
		delete newOrganism;
		return false;
	}
}