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

using namespace std;
using namespace CE;
using namespace Game;

int main() {

	///////////PRELOAD///////////

	setlocale(LC_ALL, "ru");
	srand((int)time(0));

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