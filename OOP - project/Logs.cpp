#include "Logs.h"
#include "ConstantValues.h"

Logs::Logs():BlockElement{LOGS_WIDTH,LOGS_HEIGHT,"LOGS",0,GAME_BOARD_HEIGHT+1}
{

}

void Logs::addNewLog(std::string newLine)
{
	logLines.push_back(newLine);
}



void Logs::drawLogs()
{
	drawBlockInXY();
	int lineCounter = 8;
	int numToShow = logLines.size() > 8 ? logLines.size() - 8 :0 ;
	for (int i = logLines.size()-1; i>=numToShow; i--)
	{
		blockElement.gotoxy(2,getPositionY()+(lineCounter--));
		std::cout<< logLines[i];
	}
	blockElement.gotoxy(10,33);

}

std::vector<std::string>& Logs::getLogsAdress()
{
	return logLines;
}
