#pragma once
#include <iostream>
#include <conio.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "Compontent.h"
#include "Vars.h"
#include "Maps.h"

using namespace CE;
using namespace std;

namespace Game {

	void MainMenu() {

		int choise = 0;

		int key;

		while (true)
		{
			system("cls");

			cout << "  ####    ##     ##    ####  ######    ##  ##     ##    ######  ##      ######      ####    ##  ##  ##      ##\n"
				<< "##    ##  ####   ##  ##      ##            ####   ##      ##    ##      ##        ##        ##  ##  ####  ####\n"
				<< "##    ##  ## ##  ##  ##      ######    ##  ## ##  ##      ##    ##      ######    ##        ##  ##  ##  ##  ##\n"
				<< "##    ##  ##  ## ##  ##      ##        ##  ##  ## ##      ##    ####    ##        ##  ##      ##    ##      ##\n"
				<< "##    ##  ##   ####  ##      ##        ##  ##   ####      ##    ##  ##  ##        ##    ##    ##    ##      ##\n"
				<< "  ####    ##     ##    ####  ######    ##  ##     ##      ##    ##  ##  ######      ####      ##    ##      ##\n\n\n\n";

			switch (choise)
			{
			case 0:
				cout << ">>New Game - Continue" << endl;
				break;
			case 1:
				cout << "New Game - >>Continue" << endl;
				break;
			}

			key = _getch();

			if ((key == 'D' || key == 'd') && choise < 1) choise++;
			else if ((key == 'A' || key == 'a') && choise > 0) choise--;
			else if (key == 13) break;
		}

		switch (choise)
		{
		case 0:
			Player.position = Vector2(24, 10);
			LoadMap(&MainMap, 0);
			break;
		case 1:

			break;
		}
		
		system("cls");
	}
}