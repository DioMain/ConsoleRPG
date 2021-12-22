#pragma once
#include <iostream>
#include <vector>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "Vars.h"
#include "Compontent.h"

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
					map.addGameObject(new GameObject(Vector2(x, y), '#', "Wall", ObjectType::wall));
				}
				else {
					map.addGameObject(new GameObject(Vector2(0, y), '#', "Wall", ObjectType::wall));
					map.addGameObject(new GameObject(Vector2(map.getSize().x - 1, y), '#', "Wall", ObjectType::wall));
				}
			}
		}

		// It is wall generate inside map (horizontal line)
		/*for (int x = 7; x < 13; x++) 
		{
			map.addGameObject(new GameObject(Vector2(x, 3), '#', "Wall", ObjectType::wall));
		}*/

		map.addGameObject(new GameObject(Vector2(5, 5), '#', "Wall", ObjectType::wall));

		Player.position = Vector2(24, 10);

		map.addGameObject(new GameObject(Vector2(22, 10), '?', "test", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(25, 15), '?', "F", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(40, 15), '¹', "nextlocate", ObjectType::action));
		map.addGameObject(&Player);

		return map;
	}

	GameMap Mymap() {
		GameMap map(Vector2(50, 30), ' ');

		for (int y = 0; y < map.getSize().y; y++) // WALL GENERATE //
		{
			for (int x = 0; x < map.getSize().x; x++)
			{
				if (y == 0 || y == map.getSize().y - 1) {
					map.addGameObject(new GameObject(Vector2(x, y), '#', "Wall", ObjectType::wall));
				}
				else {
					map.addGameObject(new GameObject(Vector2(0, y), '#', "Wall", ObjectType::wall));
					map.addGameObject(new GameObject(Vector2(map.getSize().x - 1, y), '#', "Wall", ObjectType::wall));
				}
			}
		}

		// It is wall generate inside map (horizontal line)
		for (int x = 1; x < 13; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 3), '#', "Wall", ObjectType::wall));
		}

		for (int y = 3; y < 10; y++)
		{
			map.addGameObject(new GameObject(Vector2(13, y), '#', "Wall", ObjectType::wall));
		}

		for (int y = 1; y < 20; y++)
		{
			map.addGameObject(new GameObject(Vector2(16, y), '#', "Wall", ObjectType::wall));
		}

		for (int x = 1; x < 13; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 17), '#', "Wall", ObjectType::wall));
		}
		//map.addGameObject(new GameObject(Vector2(5, 5), '#', "Wall", ObjectType::wall));

		Player.position = Vector2(1, 1);

		map.addGameObject(new GameObject(Vector2(3, 5), '?', "F", ObjectType::action));
		/*map.addGameObject(new GameObject(Vector2(22, 10), '?', "test", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(25, 15), '?', "F", ObjectType::action));*/
		map.addGameObject(&Player);

		return map;
	}

	void MapsInisialize() {
		Maps.push_back(DevMap());

		Maps.push_back(Mymap());
	}
}