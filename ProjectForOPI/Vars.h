#pragma once
#include <vector>
#include "DefaultMath.h"
#include "Physics.h"
#include "GraphicEngine.h"

using namespace CE;

namespace Game {
	GameMap MainMap; // CURRENT LOAD MAP //
	vector<GameMap> Maps = vector<GameMap>();

	GameObject Player(Vector2(5, 2), 'P', "Player");

	CollisionDirection WallDir(None);
}