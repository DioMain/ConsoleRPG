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

	vector<Enemy> Enemys = vector<Enemy>();

	int MaxHeal = 2000;
	int MaxArmor = 100;

	int Heal = 2000;
	int Armor = 100;
	int Damage = 250;

	GameObject Player(Vector2(5, 2), 'P', "Player");

	CollisionDirection WallDir(None);

	int BALLS = 0;
}