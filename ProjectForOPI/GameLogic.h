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
#include "Compontent.h"

using namespace std;
using namespace CE;
using namespace Game;

// Loading before start game curricular

void PreLoad(){
	MainMap = Maps[0];
}

// Loading before map render
void BeforeRender(){
	
}

// Loading after map render
void AfterRender() {
	int Key = 0;

	Heal = (Heal > MaxHeal) ? MaxHeal : Heal;
	Armor = MaxArmor;

	cout << "\nHEAL: " << Heal << '\t' << "ARMOR: " << Armor;

	Key = _getch();

	// INPUT MANAGER //

	if ((Key == 'w' || Key == 'W' || Key == 'ö' || Key == 'Ö')
		&& !Collision::NearDirectionWithWall(&MainMap, &Player, CollisionDirection(Up))) Player.position.y--; 
	else if ((Key == 's' || Key == 'S' || Key == 'û' || Key == 'Û')
		&& !Collision::NearDirectionWithWall(&MainMap, &Player, CollisionDirection(Down))) Player.position.y++;
	else if ((Key == 'd' || Key == 'D' || Key == 'â' || Key == 'Â')
		&& !Collision::NearDirectionWithWall(&MainMap, &Player, CollisionDirection(Right))) Player.position.x++;
	else if ((Key == 'a' || Key == 'A' || Key == 'ô' || Key == 'Ô')
		&& !Collision::NearDirectionWithWall(&MainMap, &Player, CollisionDirection(Left))) Player.position.x--;

}


// Loading after end game curricular
void PastLoad() {
	std::system("CLS"); // CONSOLE CLEAR //

	std::system("pause"); // CONSOLE WAIT INPUT ANY KEY //
}