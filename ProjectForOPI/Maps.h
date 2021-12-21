#pragma once
#include <iostream>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"

using namespace CE;
using namespace std;

namespace Game {

	GameMap StartMap(GameObject* Player, GameObject* Candy) {
		GameMap map(Vector2(20, 10), ' ');

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

		map.addGameObject(Player);
		map.addGameObject(Candy);

		return map;
	}

	GameMap EndMap(GameObject* Player, GameObject* Candy) {
		GameMap map(Vector2(30, 20), ' ');

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

		map.addGameObject(Player);
		map.addGameObject(Candy);

		return map;
	}
}