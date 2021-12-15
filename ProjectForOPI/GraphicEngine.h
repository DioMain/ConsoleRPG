#pragma once
#include <vector>
#include <string>
#include "DefaultMath.h"

using namespace std;

class GameObject
{
public:

	char Symbol;
	string tag;

	GameObject(char Symbol, string tag) {
		this->Symbol = Symbol;
		this->tag = tag;
	}

	GameObject(char Symbol) {
		this->Symbol = Symbol;
		this->tag = "";
	}

	GameObject() {
		this->Symbol = ' ';
		this->tag = "";
	}

private:

};

class GameMap
{
public:

	GameObject defaultObject;

	GameMap(Vector2 size, GameObject defaultObject) {
		this->size = size;
		this->defaultObject = defaultObject;

		for (int y = 0; y < size.y; y++)
		{
			Map.push_back(vector<GameObject>());
			for (int x = 0; x < size.x; x++)
			{
				Map[y].push_back(defaultObject);
			}
		}
	}

	void draw() {
		for (int y = 0; y < size.y; y++)
		{
			for (int x = 0; x < size.x; x++)
			{
				cout << Map[y][x].Symbol;
			}
			cout << endl;
		}
	}
	
	GameObject getGameObjectByMapPosition(Vector2 pos) {
		return Map[pos.y][pos.x];
	}

private:

	vector<vector<GameObject>> Map;
	Vector2 size;

};