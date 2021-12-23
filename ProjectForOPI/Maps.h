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

		map.addGameObject(new GameObject(Vector2(22, 10), 'A', "Costumes", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(25, 15), 'B', "Whip", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(40, 15), 'C', "Train", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(35, 10), 'T', "ToMyMap", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(24, 12), 'D', "ToDimas", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(30, 10), 'F', "TestB", ObjectType::action));
		map.addGameObject(&Player);

		return map;
	}

	GameMap ShMap() {
		GameMap map(Vector2(50, 25), ' ');

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

		for (int y = 1; y < 10; y++)
		{
			map.addGameObject(new GameObject(Vector2(17, y), '#', "Wall", ObjectType::wall));
		}

		for (int y = 12; y < 25; y++)
		{
			map.addGameObject(new GameObject(Vector2(17, y), '#', "Wall", ObjectType::wall));
		}

		for (int x = 17; x < 30; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 12), '#', "Wall", ObjectType::wall));
		}

		for (int x = 33; x < 50; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 12), '#', "Wall", ObjectType::wall));
		}

		for (int x = 1; x < 13; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 17), '#', "Wall", ObjectType::wall));
		}

		for (int y = 12; y < 23 ;y++)
		{
			map.addGameObject(new GameObject(Vector2(13, y), '#', "Wall", ObjectType::wall));
		}
		for (int x = 5; x < 10; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 7), '#', "Wall", ObjectType::wall));
		}

		for (int y =7; y < 9; y++)
		{
			map.addGameObject(new GameObject(Vector2(5, y), '#', "Wall", ObjectType::wall));
		}

		for (int y = 7; y < 9; y++)
		{
			map.addGameObject(new GameObject(Vector2(9, y), '#', "Wall", ObjectType::wall));
		}

		for (int x = 5; x < 10; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 9), '#', "Wall", ObjectType::wall));
		}

		for (int x = 5; x < 10; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 12), '#', "Wall", ObjectType::wall));
		}

		for (int y = 12; y < 14; y++)
		{
			map.addGameObject(new GameObject(Vector2(5, y), '#', "Wall", ObjectType::wall));
		}

		for (int y = 12; y < 14; y++)
		{
			map.addGameObject(new GameObject(Vector2(9, y), '#', "Wall", ObjectType::wall));
		}

		for (int x = 5; x < 10; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 14), '#', "Wall", ObjectType::wall));
		}

		for (int x = 17; x < 45; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 9), '#', "Wall", ObjectType::wall));
		}

		map.addGameObject(new GameObject(Vector2(10, 4), '*', "Dumbbell", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(35, 22), 'B', "Costumes", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(40, 5), 'C', "Cumpot", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(40, 10), '~', "Whip", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(10, 10), ':', "Train", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(3, 20), '?', "None", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(35, 10), 'M', "ToNextMap", ObjectType::action));
		map.addGameObject(&Player);

		return map;
	}

	GameMap AsMap() {
		GameMap map(Vector2(50, 25), ' ');

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
		for (int x = 1; x < 26; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 13), '#', "Wall", ObjectType::wall));
		}

		for (int y = 13; y < 19; y++)
		{
			map.addGameObject(new GameObject(Vector2(24, y), '#', "Wall", ObjectType::wall));
		}

		for (int x = 1; x < 18; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 18), '#', "Wall", ObjectType::wall));
		}

		for (int x = 23; x < 24; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 18), '#', "Wall", ObjectType::wall));
		}

		for (int x = 30; x < 49; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 13), '#', "Wall", ObjectType::wall));
		}

		for (int y = 13; y < 20; y++)
		{
			map.addGameObject(new GameObject(Vector2(30, y), '#', "Wall", ObjectType::wall));
		}

		for (int y = 17; y < 24; y++)
		{
			map.addGameObject(new GameObject(Vector2(42, y), '#', "Wall", ObjectType::wall));
		}

		for (int x = 30; x < 34; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 17), '#', "Wall", ObjectType::wall));
		}

		for (int x = 38; x < 42; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 17), '#', "Wall", ObjectType::wall));
		}

		for (int y = 5; y < 10; y++)
		{
			map.addGameObject(new GameObject(Vector2(24, y), '#', "Wall", ObjectType::wall));
		}

		for (int x = 24; x < 37; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 10), '#', "Wall", ObjectType::wall));
		}

		for (int y = 10; y < 14; y++)
		{
			map.addGameObject(new GameObject(Vector2(37, y), '#', "Wall", ObjectType::wall));
		}

		for (int y = 1; y < 8; y++)
		{
			map.addGameObject(new GameObject(Vector2(37, y), '#', "Wall", ObjectType::wall));
		}

		for (int x = 37; x < 41; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 8), '#', "Wall", ObjectType::wall));
		}

		for (int x = 46; x < 49; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 8), '#', "Wall", ObjectType::wall));
		}

		for (int x = 45; x < 49; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 10), '#', "Wall", ObjectType::wall));
		}

		for (int x = 37; x < 42; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 10), '#', "Wall", ObjectType::wall));
		}

		for (int x = 37; x < 42; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 10), '#', "Wall", ObjectType::wall));
		}

		for (int x = 7; x < 16; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 3), '#', "Wall", ObjectType::wall));
		}

		for (int x = 7; x < 16; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 9), '#', "Wall", ObjectType::wall));
		}

		for (int y = 3; y < 9; y++)
		{
			map.addGameObject(new GameObject(Vector2(11, y), '#', "Wall", ObjectType::wall));
		}

		for (int y = 19; y < 23; y++)
		{
			map.addGameObject(new GameObject(Vector2(36, y), '#', "Wall", ObjectType::wall));
		}

		for (int y = 20; y < 23; y++)
		{
			map.addGameObject(new GameObject(Vector2(5, y), '#', "Wall", ObjectType::wall));
		}

		for (int y = 15; y < 17; y++)
		{
			map.addGameObject(new GameObject(Vector2(1, y), '*', "Wall", ObjectType::wall));
		}

		for (int x = 4; x < 20; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 14), '*', "Wall", ObjectType::wall));
		}

		for (int x = 28; x < 33; x++)
		{
			map.addGameObject(new GameObject(Vector2(x, 2), '#', "Wall", ObjectType::wall));
		}

		map.addGameObject(new GameObject(Vector2(24, 1), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(48, 17), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(43, 17), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(30, 23), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(30, 22), '#', "Wall", ObjectType::wall));

		map.addGameObject(new GameObject(Vector2(10, 4), '*', "dumbbell", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(35, 22), 'b', "costumes", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(40, 5), 'c', "cumpot", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(40, 10), '~', "whip", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(30, 10), ':', "train", ObjectType::action));
		map.addGameObject(new GameObject(Vector2(3, 20), '?', "none", ObjectType::action));
		map.addGameObject(&Player);

		return map;
	}

	GameMap DimasMap() {
		GameMap map = GameMap(Vector2(80, 9), ' ');

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

		map.addGameObject(new GameObject(Vector2(1, 2), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(2, 1), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(1, 6), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(2, 7), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(14, 1), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(18, 4), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(21, 2), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(22, 2), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(26, 3), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(55, 4), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(59, 4), '#', "Wall", ObjectType::wall));
		map.addGameObject(new GameObject(Vector2(59, 6), '#', "Wall", ObjectType::wall));


		for	(int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(10, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(10, 5 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 7; (i == 2) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(12 + i, 2), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 7; (i == 0) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(12 + i, 3), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 7; (i == 0) ? i += 3 : i++) map.addGameObject(new GameObject(Vector2(12 + i, 5), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 4; i++) map.addGameObject(new GameObject(Vector2(12 + i, 6), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(18 + i, 7), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 8; i++) map.addGameObject(new GameObject(Vector2(20 + i, 5), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 2; i++) map.addGameObject(new GameObject(Vector2(22, 6 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 2; i++) map.addGameObject(new GameObject(Vector2(27, 6 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(20, 2 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(20, 2 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(23, 2 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(25, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(27, 1 + i), '#', "Wall", ObjectType::wall));

		// room
		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(31, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(37, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 5; (i == 1) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(32 + i, 3), '#', "Wall", ObjectType::wall));
		//

		// room
		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(39, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(45, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 5; (i == 1) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(40 + i, 3), '#', "Wall", ObjectType::wall));
		//

		// room
		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(31, 5 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(37, 5 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 5; (i == 1) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(32 + i, 5), '#', "Wall", ObjectType::wall));
		//

		// room
		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(39, 5 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 3; i++) map.addGameObject(new GameObject(Vector2(45, 5 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 5; (i == 1) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(40 + i, 5), '#', "Wall", ObjectType::wall));
		//

		for (int i = 0; i < 7; (i == 2) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(48, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 5; i++) map.addGameObject(new GameObject(Vector2(50, 2 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 7; (i == 3) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(52, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 5; i++) map.addGameObject(new GameObject(Vector2(54, 2 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 7; (i == 3) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(56, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 1; i < 7; (i == 3) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(58, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 0; i < 7; (i == 1 || i == 3 || i == 5) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(60, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 3; i < 7; i++) map.addGameObject(new GameObject(Vector2(61, 1 + i), '#', "Wall", ObjectType::wall));

		for (int i = 1; i < 7; (i == 4) ? i += 2 : i++) map.addGameObject(new GameObject(Vector2(63, 1 + i), '#', "Wall", ObjectType::wall));

		map.addGameObject(&Player);

		return map;
	}

	GameMap LastMap() {
		GameMap map = GameMap(Vector2(80, 9), ' ');

		map.addGameObject(&Player);

		return map;
	}

	void MapsInisialize() {
		Maps.push_back(DevMap());
		Maps.push_back(AsMap());
		Maps.push_back(ShMap());
		Maps.push_back(DimasMap());
		Maps.push_back(LastMap());
	}

	void LoadMap(GameMap* mainMap, int mapId) {
		(*mainMap) = Maps[mapId];
		MapId = mapId;
	}
}