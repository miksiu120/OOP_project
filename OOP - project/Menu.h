#pragma once
#include "BlockElement.h"
#include "ConstantValues.h"
class Menu:BlockElement
{
public:
	Menu();
	void drawMenu();
	void drawAsks();
	void getWidthAndHeight(int& width,int& height);
private:

};

inline Menu::Menu() :BlockElement{ MENU_WIDTH,MENI_HEIGHT,"Menu",MENU_POS_X,MENU_POS_Y }
{
}

inline void Menu::drawMenu()
{
	drawBlockInXY();
	blockElement.gotoxy(MENU_POS_X + 4,MENU_POS_Y + 2);
	std::cout << "1.Nowa gra" << std::endl;
	blockElement.gotoxy(MENU_POS_X + 4, MENU_POS_Y + 4);
	std::cout << "2.Load Game" << std::endl;
	blockElement.gotoxy(MENU_POS_X + 4, MENU_POS_Y + 6);
	std::cout << "3.Exit" << std::endl;
}
inline void Menu::drawAsks()
{
	blockElement.gotoxy(MENU_POS_X + 2, MENU_POS_Y + 8);
	std::cout << "Podaj szerokosc i\n";
	blockElement.gotoxy(MENU_POS_X + 2, MENU_POS_Y + 9);
	std::cout << " wysokosc:";
}

inline void Menu::getWidthAndHeight(int& width, int& height)
{
	blockElement.gotoxy(MENU_POS_X + 4, MENU_POS_Y + 11);
	std::cin >> width;
	blockElement.gotoxy(MENU_POS_X + 4, MENU_POS_Y + 12);
	std::cin >> height;
}
