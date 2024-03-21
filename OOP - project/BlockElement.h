#pragma once
#include "Block.h"

class BlockElement {

	int positionX;
	int positionY;
protected:
	Block blockElement;
public:
	BlockElement(int width, int height, std::string name,int posX,int posY) 
		:positionX{posX}, positionY{posY},
		blockElement{ width,height,name }
	{

	}
	int getPositionX() {
		return positionX;
	}
	int getPositionY()
	{
		return positionY;
	}
	int getWidth()
	{
		return blockElement.getWidth();
	}
	int getHeight()
	{
		return blockElement.getHeight();
	}
	void drawBlockInXY()
	{
		blockElement.drawBlock(positionX,positionY);
	}
};