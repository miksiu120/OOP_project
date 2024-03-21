#pragma once
#include "Animal.h"
#include <conio.h>
#include <string>
class World;
class Human :public Animal
{
	int alzurShieldCooldown;
	bool isShieldActive;
public:
	Human(World&,int posX,int posY);
	void action(char);
	void collision(Organism*) override;
	bool* getShieldStatus();
	int getShieldCooldown();
	void setShieldStatus(bool& status);
	void setShieldCooldown(int& cooldown);

};


