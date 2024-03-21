
#include <iostream>
#include <Windows.h>
#include "Game.h"
#include "Menu.h"
using namespace std; 


int main()
{
	srand(time(NULL));
	SetConsoleOutputCP(437);
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 550, 650, TRUE);
	Menu menuGame;

	while (true)
	{
		menuGame.drawMenu();
		int k;
		cin >> k;
		if (k == 1)
		{
			menuGame.drawAsks();
			int width, height;
			menuGame.getWidthAndHeight(width, height);

			Game newGame{width,height};
			newGame.playGame();
		}
		else if (k == 2)
		{
			Game newGame;
			newGame.loadGame();
		}
		else {
			return 0;
		}

	}
}




