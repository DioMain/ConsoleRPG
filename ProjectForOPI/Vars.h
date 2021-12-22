#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "FightSystem.h"
#include "DefaultMath.h"
#include "Physics.h"
#include "GraphicEngine.h"

using namespace CE;
using namespace std;

namespace Game {
	GameMap MainMap; // CURRENT LOAD MAP //
	vector<GameMap> Maps = vector<GameMap>();
	
	Vorag a;

	//vector<Vorag> Enemys = vector<Vorag>();

	GameObject Player(Vector2(5, 2), 'P', "Player");

	CollisionDirection WallDir(None);
}