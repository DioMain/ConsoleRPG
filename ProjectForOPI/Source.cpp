#include <iostream>
#include <conio.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "Events.h"
#include "Maps.h"
#include "FightSystem.h"
#include "Vars.h"
#include "GameLogic.h"
#include "Compontent.h"

using namespace std;
using namespace CE;
using namespace Game;

int main() { // ONCE IN THE GYM //

	///////////PRELOAD///////////
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo = CONSOLE_CURSOR_INFO();

	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &cursorInfo);

	setlocale(LC_ALL, "ru");
	srand((int)time(0));
	
	EnemysUnit();

	MapsInisialize();

	PreLoad();

	///////////PRELOAD///////////

	while (true) 
	{
		///////////BEFORE RENDER///////////

		BeforeRender();

		///////////BEFORE RENDER///////////

		MainMap.Render(); // RENDER FUNCTION

		///////////AFTER RENDER///////////

		AfterRender();

		EventUnit();

		///////////AFTER RENDER///////////
	}

	///////////PASTLOAD///////////

	PastLoad();

	return 0;
}