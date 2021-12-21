#pragma once
#include <iostream>
#include <conio.h>
#include "Vars.h"
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "Events.h"
#include "Maps.h"
#include "FightSystem.h"

using namespace std;
using namespace CE;
using namespace Game;

// Loading before start game curricular
void PreLoad(){
	MainMap = Maps[0];
}

// Loading before map render
void BeforeRender(){
	std::system("CLS"); // CONSOLE CLEAR //
}

// Loading after map render
void AfterRender() {
	int Key = 0;

	Key = _getch();

	switch (Key) // INPUT MANAGER //
	{
	case 'w':
		if (!Collision::NearDirection(&MainMap, &Player, CollisionDirection(Up), "Wall")) Player.position.y--;
		break;
	case 's':
		if (!Collision::NearDirection(&MainMap, &Player, CollisionDirection(Down), "Wall")) Player.position.y++;
		break;
	case 'd':
		if (!Collision::NearDirection(&MainMap, &Player, CollisionDirection(Right), "Wall")) Player.position.x++;
		break;
	case 'a':
		if (!Collision::NearDirection(&MainMap, &Player, CollisionDirection(Left), "Wall")) Player.position.x--;
		break;
	}
}

// Loading after end game curricular
void PastLoad() {
	std::system("CLS"); // CONSOLE CLEAR //

	std::system("pause"); // CONSOLE WAIT INPUT ANY KEY //
}