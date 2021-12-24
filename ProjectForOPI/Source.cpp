#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "Events.h"
#include "Maps.h"
#include "FightSystem.h"
#include "Vars.h"
#include "GameLogic.h"
#include "Compontent.h"
#include "UI.h"

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

	CE::SetConsoleColor(CE::white);

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	srand((int)time(0));
	
	EnemysUnit();

	MapsInisialize();

	PreLoad();

	///////////PRELOAD///////////

	while (IsLive) 
	{
		SetConsoleCursorInfo(hConsole, &cursorInfo);

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

	if (IsGameEnd) return 0;

	PastLoad();

	return 0;
}