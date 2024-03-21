#pragma once
#include "Block.h"
#include "World.h"
#include "Logs.h"
#include "ConstantValues.h"
#include "Stats.h"
#include <fstream>
#include <vector>
#include <iostream>
class Game
{
	World gameWorld;
	Logs  gameLogs;
	Stats gameStats;
	
	int turnCounter=0;	

public:

	Game();
	Game(int width,int height);
	void drawGame();
	void playGame();
	void makeActions(char pressed);
	void loadGame();
};

