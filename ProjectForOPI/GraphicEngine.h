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
	Vector2 position;

	GameObject(Vector2 position, char Symbol, string tag = "") {
		this->position = position;
		this->Symbol = Symbol;
		this->tag = tag;
	}

	GameObject() {
		this->position = Vector2();
		this->Symbol = ' ';
		this->tag = "";
	}

private:

};

class GameMap
{
public:

	char defaultSymbol;

	GameMap(Vector2 size, char defaultSymbol) {
		this->size = size;
		this->defaultSymbol = defaultSymbol;

		for (int y = 0; y < size.y; y++)
		{
			Map.push_back(vector<char>());
			for (int x = 0; x < size.x; x++)
			{
				Map[y].push_back(defaultSymbol);
			}
		}
	}

	void addGameObject(GameObject gameObject) {
		GameObjects.push_back(gameObject);
	}

	void deleteGameObjectById(int id) {
		GameObjects.erase(GameObjects.begin() + id);
	}

	void draw() {

		for (int y = 0; y < size.y; y++)
		{
			for (int x = 0; x < size.x; x++)
			{
				Map[y][x] = defaultSymbol;
			}
		}

		for (int i = 0; i < GameObjects.size(); i++)
		{
			if (GameObjects[i].position.x > -1 && GameObjects[i].position.y > -1
				&& GameObjects[i].position.x < size.x && GameObjects[i].position.y < size.y) {
				Map[GameObjects[i].position.y][GameObjects[i].position.x] = GameObjects[i].Symbol;
			}
			else {
				cout << "GameObject[" << GameObjects[i].Symbol << ", " << GameObjects[i].tag << "] - out of map area!" << endl;
			}
			
		}

		for (int y = 0; y < size.y; y++)
		{
			for (int x = 0; x < size.x; x++)
			{
				cout << Map[y][x];
			}
			cout << endl;
		}
	}
	
	GameObject getGameObjectByMapPosition(Vector2 pos) {
		GameObject obj(Vector2(), ' ', "null");

		for(int i = 0; i < GameObjects.size(); i++)
		{
			if (GameObjects[i].position == pos) { obj = GameObjects[i]; break; }
		}

		if (obj.tag == "null") cout << "GameObject no found!" << endl;
			
		return obj;
	}

	GameObject getGameObjectById(int id) {

	}

private:

	vector<GameObject> GameObjects;
	vector<vector<char>> Map;
	Vector2 size;

};