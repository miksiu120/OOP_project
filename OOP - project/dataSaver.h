#pragma once
class World;
class DataSaver
{
	World* savingElement;
public:
	DataSaver(World*);
	~DataSaver();
	void saveGame();
	void loadGame();
};


