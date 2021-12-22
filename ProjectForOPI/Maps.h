#pragma once
#include <iostream>
#include <vector>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "Vars.h"

using namespace CE;
using namespace std;

namespace Game {

	GameMap DevMap() {
		GameMap map(Vector2(50, 20), ' ');

		for (int y = 0; y < map.getSize().y; y++) // WALL GENERATE //
		{
			for (int x = 0; x < map.getSize().x; x++)
			{
				if (y == 0 || y == map.getSize().y - 1) {
					map.addGameObject(new GameObject(Vector2(x, y), '#', "Wall"));
				}
				else {
					map.addGameObject(new GameObject(Vector2(0, y), '#', "Wall"));
					map.addGameObject(new GameObject(Vector2(map.getSize().x - 1, y), '#', "Wall"));
				}
			}
		}

		Player.position = Vector2(24, 10);

		map.addGameObject(new GameObject(Vector2(22, 10), '?', "test", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(25, 15), '?', "F", ObjectType::action));
		map.addGameObject(&Player);

		return map;
	}

	void MapsInisialize() {
		Maps.push_back(DevMap());
	}
}