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
	//std::system("CLS"); // CONSOLE CLEAR //
	cout << endl << Player.position.x << "       " << endl;
}

// Loading after map render
void AfterRender() {
	int Key = 0;

	Key = _getch();

	// INPUT MANAGER //
	if ((Key == 'w' || Key == 'W' || Key == 'ö' || Key == 'Ö') 
		&& !Collision::NearDirection(&MainMap, &Player, CollisionDirection(Up), "Wall")) Player.position.y--;
	else if ((Key == 's' || Key == 'S' || Key == 'û' || Key == 'Û')
		&& !Collision::NearDirection(&MainMap, &Player, CollisionDirection(Down), "Wall")) Player.position.y++;
	else if ((Key == 'd' || Key == 'D' || Key == 'â' || Key == 'Â')
		&& !Collision::NearDirection(&MainMap, &Player, CollisionDirection(Right), "Wall")) Player.position.x++;
	else if ((Key == 'a' || Key == 'A' || Key == 'ô' || Key == 'Ô')
		&& !Collision::NearDirection(&MainMap, &Player, CollisionDirection(Left), "Wall")) Player.position.x--;
}

// Loading after end game curricular
void PastLoad() {
	std::system("CLS"); // CONSOLE CLEAR //

	std::system("pause"); // CONSOLE WAIT INPUT ANY KEY //
}