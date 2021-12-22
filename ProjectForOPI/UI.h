#pragma once
#include <iostream>
#include <conio.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "Compontent.h"

using namespace CE;
using namespace std;

namespace Game {

	void MainMenu() {

		int choise = 0;

		int key;

		while (true)
		{
			system("cls");

			switch (choise)
			{
			case 0:
				cout << ">>New Game - Continue - Exit" << endl;
				break;
			case 1:
				cout << "New Game - >>Continue - Exit" << endl;
				break;
			case 2:
				cout << "New Game - Continue - >>Exit" << endl;
				break;
			}

			key = _getch();

			if ((key == 'D' || key == 'd') && choise < 2) choise++;
			else if ((key == 'A' || key == 'a') && choise > 0) choise--;
			else if (key == 13) break;
		}

		switch (choise)
		{
		case 0:

			break;
		case 1:

			break;
		case 2:
			system("exit");
			break;
		}
	}
}