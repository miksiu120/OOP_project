#pragma once
#include <time.h>
#include <Windows.h>
#include <vector> 
#include <iostream>
#include "Coords.h"

class World;
class Organism
{
	int strength;
	int initiative;
	char asciiRepresentation;
	int age = 0;
	bool isOrganismDeleted = false;
protected:
	World& ourWorld;
	Coordinates position;
	std::string name;
	Coordinates getRandomNeighbour();
	bool canMove(Coordinates);
	bool doesDefendItself(Organism*);
public:
	Organism(World&, int, int , int, int, char,std::string);
	virtual void action() = 0;
	virtual void collision(Organism*);
	virtual void draw();
	void increaseAge();
	void killOrganism();
	bool isDeleted();

	Coordinates getEmptyNeighbour();
	Coordinates& getPosition();
	int getY() const;
	int getX() const;
	char getAscii();
	int getAge();
	int getStrength();
	int getInitiative();
	std::string getName();

	void setY(int);
	void setX(int);
	void setStrength(int newStrength);
	void setAge(int);
	void setPosition(Coordinates);

	virtual ~Organism() {}
private:

};


