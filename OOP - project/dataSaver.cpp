#include "dataSaver.h"
#include <fstream>
#include "World.h"
#include "Human.h"
#include "Animals_Include.h"
#include "Plants_Include.h"
using namespace std;
DataSaver::DataSaver(World* savingWorld) :savingElement{ savingWorld }
{

}

DataSaver::~DataSaver() {
	
}


void  DataSaver::saveGame() {
	fstream file;
	file.open("save01.txt",std::ios::out);
	file << savingElement->mapSize.x <<" " << savingElement->mapSize.y << '\n';
	file << savingElement->mapPosition.x << " " << savingElement->mapPosition.y << '\n';
	int len = savingElement->organisms.size();;
	file << len << '\n';
	file << '\n';
	for (auto organism : savingElement->organisms)
	{
		char ascii = organism->getAscii();
		int strength = organism->getStrength();;
		int initiative = organism->getInitiative();
		int age = organism->getAge();
		int x = organism->getPosition().x;
		int y = organism->getPosition().y;
		file << ascii << '\n';
		file << strength << '\n';
		file << initiative << '\n';
		file << age << '\n';
		file << x << " " << y << '\n';
		Human* human = dynamic_cast<Human*>(organism);
		if (human != nullptr)
		{
			int alzurStatus = *human->getShieldStatus();
			file << alzurStatus << '\n';
			int coolDown = human->getShieldCooldown();
			file << coolDown << '\n';
		}
		file << '\n';
	}
	file << "========== \n";
	int killLen = savingElement->killList.size();;
	file << killLen << '\n';
	for(int i=0;i<savingElement->organisms.size();i++)
	{
		for (int j = 0; j<savingElement->killList.size(); j++)
		{
			if (savingElement->organisms[i] == savingElement->killList[j])
			{
				file << i << '\n';
			}
		}
	}
	file.close();
}

void DataSaver::loadGame()
{
	fstream file;
	file.open("save01.txt", std::ios::in);
	file >> savingElement->mapSize.x >> savingElement->mapSize.y;
	file >> savingElement->mapPosition.x >> savingElement->mapPosition.y;
	int lenOrg;
	file >> lenOrg;

	for (int i = 0; i < lenOrg; i++)
	{
		char element;
		int strength;
		int initiative;
		int age;
		int posX;
		int posY;
		file >> element;
		if (element == '\n')
		{
			i--;
			continue;
		}
		file >> strength;
		file >> initiative;
		file >> age;
		file >> posX >> posY;

		if (element == 'W')
		{
			
			Wolf* copiedWolf = new Wolf{*savingElement,posX,posY};
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			savingElement->organisms.push_back(copiedWolf);
		}
		else if (element == 'S')
		{
			Sheep* copiedWolf = new Sheep{ *savingElement,posX,posY };
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			savingElement->organisms.push_back(copiedWolf);
		}
		else if (element == 'F')
		{
			Fox* copiedWolf = new Fox{ *savingElement,posX,posY };
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			savingElement->organisms.push_back(copiedWolf);
		}
		else if (element == 'T')
		{
			Turtle* copiedWolf = new Turtle{ *savingElement,posX,posY };
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			savingElement->organisms.push_back(copiedWolf);
		}
		else if (element == 'A')
		{
			Antylope* copiedWolf = new Antylope{ *savingElement,posX,posY };
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			savingElement->organisms.push_back(copiedWolf);
		}
		else if (element == 'B')
		{

			Belladonna* copiedWolf = new Belladonna{ *savingElement,posX,posY };
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			savingElement->organisms.push_back(copiedWolf);
		}
		else if (element == 'D')
		{
			Dandelion* copiedWolf = new Dandelion{ *savingElement,posX,posY };
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			savingElement->organisms.push_back(copiedWolf);
		}
		else if (element == 'G')
		{
			Grass* copiedWolf = new Grass{ *savingElement,posX,posY };
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			savingElement->organisms.push_back(copiedWolf);
		}
		else if (element == 'U')
		{
			Guarana* copiedWolf = new Guarana{ *savingElement,posX,posY };
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			savingElement->organisms.push_back(copiedWolf);
		}
		else if (element == 'O')
		{
			SosnowskiBarszcz* copiedWolf = new SosnowskiBarszcz{ *savingElement,posX,posY };
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			savingElement->organisms.push_back(copiedWolf);
		}
		else if (element == '7')
		{
			bool alzurStatus{};
			int alzurCooldown{};
			file>> alzurStatus;
			file>> alzurCooldown;
			Human* copiedWolf = new Human{ *savingElement,posX,posY };
			copiedWolf->setStrength(strength);
			copiedWolf->setStrength(initiative);
			copiedWolf->setAge(age);
			copiedWolf->setShieldStatus(alzurStatus);
			copiedWolf->setShieldCooldown(alzurCooldown);
			savingElement->organisms.push_back(copiedWolf);
			savingElement->setHumanPosition(Coordinates{ posX,posY });
			savingElement->mainCharacter = copiedWolf;
		}

	}


	int lenKill;
	file >> lenKill;
	
	for (int i = 0; i < lenKill; i++)
	{
		int index;
		file >> index;
		savingElement->killList.push_back(savingElement->organisms[index]);
	}
}