#pragma once
#include "BlockElement.h"
#include "ConstantValues.h"
#include <vector>
#include "Coords.h"
class Stats:BlockElement {
	Coordinates* HumanCoordinates;
	bool* alzurStatus;
	std::string signature = "Michal Turski 193453";
	std::vector<std::string>definitionsOfLetters{
		"W - wilk",
		"S - owca",
		"F - lis",
		"T - zolw",
		"A - antylopa", 
		"B - wilcza jagoda",
		"D - mleczyk",
		"G - trawa",
		"U - guarana",
		"O - barszcz"
	};
	friend class DataSaver;
public:
	Stats();
	void drawStats();
	void setHumanCoordinates(Coordinates*);
	void setShieldStatus(bool*);
};