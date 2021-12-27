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
	bool IsGameEnd = false;

	vector<Enemy> Enemys = vector<Enemy>();

	int MaxHeal = 0;
	int MaxStamina = 0;

	int Heal = 0;
	int Armor = 0;
	int Damage = 0;

	GameObject Player(Vector2(5, 2), 'P', "Player");

	CollisionDirection WallDir(None);

	void ResetVars() {
		MaxHeal = 1000;
		MaxStamina = 20;

		Heal = 1000;
		Armor = 25;
		Damage = 80;

		IsLive = true;
		IsGameEnd = false;
	}
}