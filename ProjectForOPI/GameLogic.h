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
#include "UI.h"
#include "SaveLoad.h"

using namespace std;
using namespace CE;
using namespace Game;

// Loading before start game curricular

void PreLoad(){
	MainMenu();
}

// Loading before map render
void BeforeRender(){
	
}

// Loading after map render
void AfterRender() {
	int Key = 0;

	Heal = (Heal > MaxHeal) ? MaxHeal : Heal;

	if (Heal <= 0) {
		IsLive = false;
		return;
	}
	else true;

	cout << "\nHEAL: " << Heal << '\t' << "ARMOR: " << Armor << endl;

	Key = _getch();

	// INPUT MANAGER //

	if ((Key == 'w' || Key == 'W')
		&& !Collision::NearDirectionWithWall(&MainMap, &Player, CollisionDirection(Up))) Player.position.y--;
	else if ((Key == 's' || Key == 'S')
		&& !Collision::NearDirectionWithWall(&MainMap, &Player, CollisionDirection(Down))) Player.position.y++;
	else if ((Key == 'd' || Key == 'D')
		&& !Collision::NearDirectionWithWall(&MainMap, &Player, CollisionDirection(Right))) Player.position.x++;
	else if ((Key == 'a' || Key == 'A')
		&& !Collision::NearDirectionWithWall(&MainMap, &Player, CollisionDirection(Left))) Player.position.x--;
	else if (Key == 27) MainMenu();

}


// Loading after end game curricular
void PastLoad() {
	std::system("CLS"); // CONSOLE CLEAR //

	SetConsoleColor(CE::whitered);	

	cout << 
		"##  ##   ####   ##  ##    ##   #####    #####   ######   ####   #####   ##\n"
		"##  ##  ##  ##  ##  ##        ##        ##  ##  ##      ##  ##  ##  ##  ##\n"
		" ####   ##  ##  ##  ##    ##  #####     ##  ##  ######  ######  ##  ##  ##\n"
		"  ##    ##  ##  ##  ##    ##      ##    ##  ##  ##      ##  ##  ##  ##  ##\n"
		"  ##    ##  ##  ##  ##    ##      ##    ##  ##  ##      ##  ##  ##  ##    \n"
		"  ##     ####    ####     ##  #####     #####   ######  ##  ##  #####   ##\n\n\n";

	SetConsoleColor(CE::white);

	Sleep(2000);

	std::system("pause"); // CONSOLE WAIT INPUT ANY KEY //
}