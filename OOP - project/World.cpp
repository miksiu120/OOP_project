#include <algorithm>
#include <math.h>
#include <iostream>

#include "World.h"
#include "ConstantValues.h"
#include "Human.h"


Organism* World::getRandomOrganism()
{
	int randomNumberOfOrg = rand() % 10;
	//randomNumberOfOrg = 4;
	if (randomNumberOfOrg == 0)
	{
		Antylope* newOrganism = new Antylope{*this,rand() % (mapSize.x-3) + 2,rand() % (mapSize.y - 3) + 2 };
		return newOrganism;
	}
	else if (randomNumberOfOrg == 1)
	{
		Fox* newOrganism = new Fox{ *this,rand() % (mapSize.x - 3) + 2,rand() % (mapSize.y - 3) + 2 };
		return newOrganism;
	}
	else if (randomNumberOfOrg == 2)
	{
		Sheep* newOrganism = new Sheep{ *this,rand() % (mapSize.x - 3) + 2,rand() % (mapSize.y - 3) + 2 };
		return newOrganism;
	}
	else if (randomNumberOfOrg == 3)
	{
		Turtle* newOrganism = new Turtle{ *this,rand() % (mapSize.x - 3) + 2,rand() % (mapSize.y - 3) + 2 };
		return newOrganism;
	}
	else if (randomNumberOfOrg == 4)
	{
		Wolf* newOrganism = new Wolf{ *this,rand() % (mapSize.x - 3) + 2,rand() % (mapSize.y - 3) + 2 };
		return newOrganism;
	}
	else if (randomNumberOfOrg == 5)
	{
		Belladonna* newOrganism = new Belladonna{ *this,rand() % (mapSize.x - 3) + 2,rand() % (mapSize.y - 3) + 2 };
		return newOrganism;
	}
	else if (randomNumberOfOrg == 6)
	{
		Dandelion* newOrganism = new Dandelion{ *this,rand() % (mapSize.x - 3) + 2,rand() % (mapSize.y - 3) + 2 };
		return newOrganism;
	}
	else if (randomNumberOfOrg == 7)
	{
		Grass* newOrganism = new Grass{ *this,rand() % (mapSize.x - 3) + 2,rand() % (mapSize.y - 3) + 2 };
		return newOrganism;
	}
	else if (randomNumberOfOrg == 8)
	{
		Guarana* newOrganism = new Guarana{ *this,rand() % (mapSize.x - 3) + 2,rand() % (mapSize.y - 3) + 2 };
		return newOrganism;
	}
	else
	{
		SosnowskiBarszcz* newOrganism = new SosnowskiBarszcz{ *this,rand() % (mapSize.x - 3) + 2,rand() % (mapSize.y - 3) + 2 };
		return newOrganism;
	}

}

void World::drawOrganisms()
{
	for (int i = 0; i < organisms.size(); i++)
	{
		if (organisms[i]->getPosition().x + mapPosition.x > 0 and organisms[i]->getPosition().x + mapPosition.x < GAME_BOARD_WIDTH -1 and
			organisms[i]->getPosition().y + mapPosition.y>0 and organisms[i]->getPosition().y + mapPosition.y < GAME_BOARD_HEIGHT -1)
		{

			blockElement.gotoxy(organisms[i]->getPosition().x + mapPosition.x, organisms[i]->getPosition().y + mapPosition.y);
			organisms[i]->draw();
		}
	}
}

bool World::getKeyboardMap(char pressed)
{
	if (pressed == 'k')
	{
		if(-mapPosition.y + GAME_BOARD_HEIGHT  < (mapSize.y))
		mapPosition.y--;
		return true;
			
	}
	else if (pressed == 'l')
	{
		if (-mapPosition.x + GAME_BOARD_WIDTH < (mapSize.x))
			mapPosition.x--;
		return true;
	}
	else if (pressed == 'i')
	{
		if(mapPosition.y<0)
		mapPosition.y++;
		return true;
	}
	else if (pressed == 'j')
	{
		if (mapPosition.x < 0)
		mapPosition.x++;
		return true;
	}
	return false;
}


void World::killOrganismsFromKillList()
{
	for (int i = 0; i < killList.size(); i++)
	{
		for (int j = 0; j < organisms.size(); j++)
		{
			if (killList[i] == organisms[j])
			{
				Human* human = dynamic_cast<Human*>(killList[i]);
				if (human != nullptr)
				{
					delete mainCharacter;
					mainCharacter = nullptr;
				}
				else
					delete organisms[j];
				killList.erase(killList.begin() + i);
				organisms.erase(organisms.begin() + j);
				i--;
				j--;
				break;
			}
		}
	}
}

World::World(int worldWidth,int worldHeight)
	:dataSaver{this},mapSize {
	worldWidth, worldHeight
}, BlockElement{ GAME_BOARD_WIDTH,GAME_BOARD_HEIGHT,"GAMEBOARD",GAME_BOARD_POS_X,GAME_BOARD_POS_Y },
	TOP_BORDER{ GAME_BOARD_POS_X },LEFT_BORDER{ GAME_BOARD_POS_Y },
	BOTTOM_BORDER{ GAME_BOARD_HEIGHT },RIGHT_BORDER{ GAME_BOARD_WIDTH },
	mainCharacter{ new Human{ *this,10,10 } }
{
	mapPosition.y = 0;
	mapPosition.x = 0;
}

void World::drawWorld()
{
	blockElement.drawBlock(getPositionX(), getPositionY());
	drawOrganisms();
}

bool comparator(Organism* first,Organism* second)
{
	if (first->getInitiative() > second->getInitiative())
		return  true;
	else if(first->getInitiative() == second->getInitiative())
		if (first->getAge() > second->getAge())
		{
			return true;
		}
	return false;
}		


void World::setUpWorld()
{

	killList.clear();
	organisms.clear();


	if (mainCharacter != nullptr)
	{
		delete mainCharacter;
	}
		mainCharacter =  new Human{ *this,10,10 } ;
	int numberOfElements = mapSize.x * mapSize.y * 0.06;
	for (int i = 0; i < numberOfElements; i++)
	{
		Organism* newOrganism = getRandomOrganism();
		organisms.push_back(newOrganism);
	}
	organisms.push_back(mainCharacter);

}

void World::makeActions(char pressed)
{
	int numberOfOrganisms = organisms.size();
	for (int i=0;i<numberOfOrganisms;i++)
	{
		if (organisms[i]->isDeleted() == false)
		{
			Human* human = dynamic_cast<Human*>(organisms[i]);
			if (human == nullptr)
			{
				organisms[i]->action();
			}
			else
			{
				drawWorld();
				pressed = _getch();
				if (getKeyboardMap(pressed))
				{
					i--;
					this->drawWorld();
					continue;
				}
				else if (pressed == 'z')
					dataSaver.saveGame();
				else if (pressed == 'x')
				{
					loadGame();
					return;
				}

				human->action(pressed);
			}
			organisms[i]->increaseAge();
		}
	}

	killOrganismsFromKillList();
	sort(organisms.begin(), organisms.end(), comparator);
}

void World::addNewElementToWorld(Organism* newElement)
{
	organisms.push_back(newElement);
	
}

void World::addNewLog(std::string log)
{
	logsPointer->push_back(log);
}

void World::loadGame()
{
	organisms.clear();
	killList.clear();
	logsPointer->clear();

	dataSaver.loadGame();
}

bool* World::getAlzurStatus()
{
	return mainCharacter->getShieldStatus();
}
bool World::isHumanAlive()
{
	if (mainCharacter != nullptr)
		return true;
	return false;

}

const int World::getTopBorder()
{
	return 1;
}

const int World::getLeftBorder()
{
	return 1;
}

const int World::getBottomBorder()
{
	return mapSize.y - 1;
}

const int World::getRightBorder()
{
	return mapSize.x - 1;
}

Coordinates* World::getHumanPosition()
{
	return &this->mainCharacter->getPosition();
}

void World::setHumanPosition(Coordinates cords)
{
	mainCharacter->setPosition(cords);
}

void World::addToKillList(Organism& deleting)
{
	deleting.killOrganism();
	killList.push_back(&deleting);
}

Organism* World::getFromPostion(Coordinates& checkingCoords)
{
	for (auto element : organisms)
	{
		if (element->getPosition() == checkingCoords)
		{
			return element;
		}
	}
	return nullptr;
}




Organism* World::getFromPostion(Coordinates&& checkingCoords)
{
	for (auto element : organisms)
	{
		if (element->getPosition() == checkingCoords)
		{
			return element;
		}
	}
	return nullptr;
}

void World::connectPointerToLogs(std::vector<std::string>* logsPointer)
{
	this->logsPointer = logsPointer;
}

World:: ~World() {
	for (int i = 0; i < organisms.size(); i++)
	{
		delete organisms[i];
	}
	organisms.clear();
	killList.clear();


}