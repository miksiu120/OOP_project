#include "Stats.h"

Stats::Stats() :BlockElement{ STATS_WIDTH,STATS_HEIGHT,"STATS_AND_MANUAL",GAME_BOARD_WIDTH,0 },HumanCoordinates{ nullptr }
{

}


void Stats::setHumanCoordinates(Coordinates* newCords)
{
	HumanCoordinates = newCords;
}

void Stats::drawStats()
{
	drawBlockInXY();
	
	blockElement.gotoxy(GAME_BOARD_WIDTH + 2, 2);
	std::cout << signature;
	blockElement.gotoxy(GAME_BOARD_WIDTH + 2, 3);
	std::cout<<"Position (" << HumanCoordinates->x << "," << HumanCoordinates->y<<")";
	blockElement.gotoxy(GAME_BOARD_WIDTH + 2, 4);
	std::cout << "Alzur shield:" << (*alzurStatus ? "ACTIVE" : "INACTIVE");
	for (int i = 0; i < definitionsOfLetters.size(); i++)
	{
		blockElement.gotoxy(GAME_BOARD_WIDTH+2, 11 + i);
		std::cout << definitionsOfLetters[i] << std::endl;
	}
	
}

void Stats::setShieldStatus(bool* shielStatus)
{
	alzurStatus = shielStatus;
}
