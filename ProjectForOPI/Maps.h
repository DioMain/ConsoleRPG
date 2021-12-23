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
		map.addGameObject(new GameObject(Vector2(40, 10), 'D', "ToDimas", ObjectType::action));
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

		map.addGameObject(&Player);

		return map;
	}

	void MapsInisialize() {
		Maps.push_back(DevMap());
		Maps.push_back(ShMap());
		Maps.push_back(DimasMap());
	}

	void LoadMap(GameMap* mainMap, int mapId) {
		(*mainMap) = Maps[mapId];
		MapId = mapId;
	}
}