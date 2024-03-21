#include "Game.h"
#include "Coords.h"

using namespace std;

Game::Game()
	:
	gameStats{},
	gameLogs{},
	gameWorld{50,50}
{

}

Game::Game(int width, int height)
	:
	gameStats{},
	gameLogs{},
	gameWorld{ width,height }
{

}

void Game::drawGame()
{
	gameWorld.drawWorld();
	gameStats.drawStats();
	gameLogs.drawLogs();
	std::cout << ++turnCounter << std::endl;
}

void Game::playGame()
{
	char pressed = 'a';
	gameWorld.setUpWorld();
	gameStats.setHumanCoordinates(gameWorld.getHumanPosition());
	gameStats.setShieldStatus(gameWorld.getAlzurStatus());
	gameWorld.connectPointerToLogs(&gameLogs.getLogsAdress());
	
	while (gameWorld.isHumanAlive())
	{
		drawGame();

		if (iswalnum(pressed))
		{
			makeActions(pressed);
			std::cout << pressed << std::endl;
			system("cls");
		}
	}
	
	
}

void Game::makeActions(char pressed)
{
	gameWorld.makeActions(pressed);
}

void Game::loadGame()
{

	char pressed = 'a';
	gameWorld.setUpWorld();
	gameWorld.connectPointerToLogs(&gameLogs.getLogsAdress());
	gameWorld.loadGame();
	gameStats.setHumanCoordinates(gameWorld.getHumanPosition());
	gameStats.setShieldStatus(gameWorld.getAlzurStatus());
	
	while (gameWorld.isHumanAlive())
	{
		drawGame();

		if (iswalnum(pressed))
		{
			makeActions(pressed);
			std::cout << pressed << std::endl;
			system("cls");
		}
	}
}
