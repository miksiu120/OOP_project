#include "Organism.h"
#include "World.h"

bool Organism::canMove(Coordinates newCoords)
{
	if (ourWorld.getTopBorder() < newCoords.y and
		this->ourWorld.getLeftBorder() < newCoords.x and
		this->ourWorld.getBottomBorder()-1 > newCoords.y and
		this->ourWorld.getRightBorder()-1 > newCoords.x)
		return true;
	else
		return false;
}
Organism::Organism(World& ourWorld, int strength = -1, int initiative = -1, int x = -1, int y = -1,
	char asciiRep = '#',std::string name = "organizm") :
	ourWorld{ ourWorld }, strength{ strength }, initiative{ initiative }, position{ x,y },
	asciiRepresentation{ asciiRep },name{name}
{}

Coordinates Organism::getRandomNeighbour()
{
	int direction = rand() % 4;
	if (direction == 0)
		return Coordinates{ 1,0 };
	else if (direction == 1)
		return Coordinates{ 0,1 };
	else if (direction == 2)
		return Coordinates{ -1,0 };
	else
		return Coordinates{ 0,-1 };

}






void Organism::collision(Organism* compared)
{
	if (this == nullptr or compared == nullptr)
	{
		return;
	}
	if (this->getAscii() != compared->getAscii())
	{
		if (
			this->getStrength() < compared->getStrength())
		{
			ourWorld.addToKillList(*this);
		
			ourWorld.addNewLog(this->name + " ginie od " + compared->name);
		}
		else {
			ourWorld.addToKillList(*compared);
			ourWorld.addNewLog(compared->name + " ginie od " + this->name);
		}
	}
}

Coordinates Organism::getEmptyNeighbour()
{
	Organism* cords = ourWorld.getFromPostion
	(Coordinates{ this->getX(),this->getY() + 1 });
	if (cords == nullptr and canMove(Coordinates{ this->getX(),this->getY() + 1 }))
		return Coordinates{ this->getX(),this->getY() + 1 };

	cords = ourWorld.getFromPostion
	(Coordinates{ this->getX() + 1 ,this->getY()});
	if (cords == nullptr and canMove(Coordinates{ this->getX() + 1 ,this->getY()}))
		return Coordinates{ this->getX() + 1 ,this->getY()};
	
    cords = ourWorld.getFromPostion
	(Coordinates{ this->getX(),this->getY() - 1 });
	if (cords == nullptr and canMove(Coordinates{ this->getX(),this->getY()-1 }))
		return Coordinates{ this->getX(),this->getY() - 1 };

	cords = ourWorld.getFromPostion
	(Coordinates{ this->getX() - 1,this->getY() });
	if (cords == nullptr and canMove(Coordinates{ this->getX() - 1 ,this->getY()}))
		return Coordinates{ this->getX() - 1 ,this->getY()};
	else
	{
		return Coordinates{ -1,-1 };
	}
}

void Organism::draw()
{
	std::cout<< asciiRepresentation;
}

Coordinates& Organism::getPosition()
{
	return position;
}
void Organism::setPosition(Coordinates cords)
{
	position = cords;
}
int Organism::getX() const
{
	return position.x;
}

char Organism::getAscii()
{
	return asciiRepresentation;
}

int Organism::getY() const
{
	return position.y;
}

void Organism::setY(int newY)
{
	position.y = newY;
}
void Organism::setX(int newX)
{
	position.x = newX;
}
int Organism::getStrength() {
	return strength;
}
void Organism::setStrength(int newStrength)
{
	strength = newStrength;
}
int Organism::getInitiative()
{
	return  initiative;
}

std::string Organism::getName() {
	return name;
}
void Organism::increaseAge()
{
	age++;
}
int Organism::getAge() {
	return age;
}
void Organism::setAge(int age)
{
	this->age = age;
}

bool Organism::doesDefendItself(Organism* element) {
	return element->getStrength() >= 5 ? true : false;
}

void Organism::killOrganism()
{
	this->isOrganismDeleted = true;
}

bool Organism::isDeleted()
{
	return isOrganismDeleted;
}
