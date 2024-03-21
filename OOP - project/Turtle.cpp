#include "Turtle.h"
#include "World.h"

Turtle::Turtle(World& ourWorld, int posX, int posY)
	:Animal{ ourWorld,2,1,posX,posY,'T',"Zolw"}
{

}

void Turtle::action()
{
	if (rand() % 4 == 1)
	{
		Animal::action();
	}
}

void Turtle ::collision(Organism* element)
{
	if (element == nullptr or this == nullptr)
	{
		return;
	}
	if (element->getStrength() >= 5)
		Organism::collision(element);

	else
		tryCopulate(element);
	
}