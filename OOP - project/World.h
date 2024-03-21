#pragma once
#include <typeinfo>
#include <vector>
#include "BlockElement.h"
#include "Coords.h"
#include "Animals_Include.h"
#include "Plants_Include.h"
#include "dataSaver.h"
class Human;
class World : public BlockElement
{
	DataSaver dataSaver;
	Coordinates mapSize;
	Coordinates mapPosition;
	Human* mainCharacter;
	std::vector<Organism*>organisms;
	std::vector<Organism*>killList;
	std::vector<std::string>* logsPointer;
	const int LEFT_BORDER;
	const int TOP_BORDER;
	const int RIGHT_BORDER;
	const int BOTTOM_BORDER;
	Organism* getRandomOrganism();
	void drawOrganisms();
	bool getKeyboardMap(char pressed);
	void killOrganismsFromKillList();
	friend class DataSaver;
public:
	World(int,int);
	void drawWorld();
	void setUpWorld();
	void addNewElementToWorld(Organism*);
	void addNewLog(std::string);
	void makeActions(char);
	void loadGame();
	bool* getAlzurStatus();
	bool isHumanAlive();
	const int getTopBorder();
	const int getLeftBorder();
	const int getBottomBorder();
	const int getRightBorder();
	Coordinates* getHumanPosition();
	void setHumanPosition(Coordinates cords);
	void addToKillList(Organism& );	
	Coordinates getEmptyNeighbour(Organism*);
	Organism* getFromPostion(Coordinates&);
	Organism* getFromPostion(Coordinates&&);
	void connectPointerToLogs(std::vector<std::string>*);
	~World();

};
