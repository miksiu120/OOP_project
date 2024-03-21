#pragma once
#include "BlockElement.h"
#include <vector>
#include "Coords.h"
class Logs:BlockElement
{

	
	std::vector<std::string>logLines{"Test 1 was eaten by test 2", "Your mom was beaten your bro","Lorem ipsum dolor sit amet",
	"Bella donna was fucked by his stepbrother","Another stupid line to my project"};
public:

	Logs();
	
	void addNewLog(std::string);
	
	void drawLogs();
	std::vector<std::string>& getLogsAdress();
};

