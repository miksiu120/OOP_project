#include "Human.h"
#include "World.h"
Human::Human(World& ourWorld, int posX, int posY) :
	Animal{ ourWorld,5,4,posX,posY,'7',"Czlowiek"}, alzurShieldCooldown{0}, isShieldActive{false}
{

}

void Human::action(char ascii)
{
	if (alzurShieldCooldown > 0)
	{
		alzurShieldCooldown--;
	}
	if (ascii == 'a' and canMove(Coordinates{ getX() - 1,getY() }))
	{
		Organism* potencial = ourWorld.getFromPostion(Coordinates{ getX() - 1,getY() });
		ourWorld.addNewLog("Czlowiek idzie na pole (" + std::to_string(getX() - 1) + " " + std::to_string(getY()) + ")");
		collision(potencial);
		setX(getX() - 1);
	}
	else if (ascii == 'w' and canMove(Coordinates{ getX(),getY() - 1 }))
	{
		Organism* potencial = ourWorld.getFromPostion(Coordinates{ getX(),getY() - 1 });
		ourWorld.addNewLog("Czlowiek idzie na pole (" + std::to_string(getX()) + " " + std::to_string(getY() - 1) + ")");
		collision(potencial);
		setY(getY() - 1);
	}
	else if (ascii == 's' and canMove(Coordinates{ getX() ,getY() + 1 }))
	{
		Organism* potencial = ourWorld.getFromPostion(Coordinates{ getX() ,getY() + 1 });
		ourWorld.addNewLog("Czlowiek idzie na pole (" + std::to_string(getX()) + " " + std::to_string(getY() + 1) + ")");
		collision(potencial);
		setY(getY() + 1);
	}
	else if (ascii == 'd' and canMove(Coordinates{ getX() + 1,getY() }))
	{
		Organism* potencial = ourWorld.getFromPostion(Coordinates{ getX() + 1,getY() });
		ourWorld.addNewLog("Czlowiek idzie na pole (" + std::to_string(getX() + 1) + " " + std::to_string(getY()) + ")");
		collision(potencial);
		setX(getX() + 1);
	}
	if (alzurShieldCooldown == 5)
	{
		isShieldActive = false;
	}
	if (ascii == 'g' and alzurShieldCooldown == 0)
	{
		alzurShieldCooldown = 10;
		isShieldActive = true;
	}
}
void Human::collision(Organism* attacker)
{
	if (attacker == nullptr or this == nullptr)
	{
		return;
	}
	Animal* animal = dynamic_cast<Animal*>(attacker);
	if (isShieldActive == false)
	{
		Organism::collision(attacker);
	}
	else if (animal != nullptr) {
		Coordinates newCords = this->getEmptyNeighbour();
		if (newCords.x != -1 and newCords.y != -1)
		{

			attacker->setPosition(newCords);
		}
	}

}

 bool* Human::getShieldStatus()
{
	return &isShieldActive;
}

 int Human::getShieldCooldown()
 {
	 return alzurShieldCooldown;
 }

 void Human::setShieldStatus(bool &status)
 {
	 isShieldActive = status;
 }
 void Human::setShieldCooldown(int &cooldown)
 {
	 alzurShieldCooldown = cooldown;
 }