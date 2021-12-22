#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "FightSystem.h"
#include "DefaultMath.h"
#include "Physics.h"
#include "GraphicEngine.h"
#include "Compontent.h"

using namespace CE;
using namespace std;

namespace Game {
	GameMap MainMap; // CURRENT LOAD MAP //
	vector<GameMap> Maps = vector<GameMap>();
	int MapId = 0;

	bool IsLive = true;

	vector<Enemy> Enemys = vector<Enemy>();

	int MaxHeal = 2000;
	int MaxStamina = 20;

	int Heal = 1000;
	int Armor = 20;
	int Damage = 50;

	GameObject Player(Vector2(5, 2), 'P', "Player");

	CollisionDirection WallDir(None);

}