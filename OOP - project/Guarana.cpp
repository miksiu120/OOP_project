#include "Guarana.h"
#include "World.h"

Guarana::Guarana(World& ourWorld, int posX, int posY)
	:Plant{ ourWorld,0,posX,posY,'U',5,"Guarana"}
{

}

void Guarana::collision(Organism* element)
{
	Animal* animal = static_cast<Animal*>(element);
	if (animal != nullptr)
	{	
		element->setStrength(element->getStrength() + 3);
	}
	Organism::collision(element);


}