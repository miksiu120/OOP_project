#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>



class Block
{
	int width;
	int height;
	std::string *border;
	std::string title;
	


public:
	Block() :width{}, height{}, border{ nullptr }, title{ title }
	{

	}
	Block(int width,int height,std::string title)
		:width{width},height{height},title{title}
	{
		border = new std::string[height];
		for (int i = 0; i < height; i++)
			border[i].assign(width, ' ');
		
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 and j == 0) // left top 
				{
					border[i][j] = '\xC9';
				}
				else if (i == 0 and j == width - 1) // right top
				{
					border[i][j] = '\xBB';
				}
				else if (i == height - 1 and j == 0) // bottom left
				{
					border[i][j] = '\xC8';
				}
				else if (i == height - 1 and j == width - 1)// bottom right
				{
					border[i][j] = '\xBC';
				}
				else if (j == 0 or j == width - 1) // horizontal lines 
				{
					border[i][j] = '\xBA';
				}
				else if (i == 0 or i == height - 1) // vertical lines
				{
					border[i][j] = '\xCD';
				}
				else
					border[i][j] = ' ';
			}
		}
		
		setTitle();

	}

	void gotoxy(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void setTitle()
	{
		for (int i = 0; i < title.size(); i++)
			border[0][i + 3] = title[i];
	}

	void drawBlock(int positionX,int positionY)
	{
		for (int i = 0; i < height; i++)
		{
			gotoxy(positionX,positionY+i);
			std::cout << border[i] << std::endl;
		}
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}
};