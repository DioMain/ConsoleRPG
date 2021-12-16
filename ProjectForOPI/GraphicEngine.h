#pragma once
#include <vector>
#include <string>
#include "DefaultMath.h"

using namespace std;


// This class contains information about the game object (Symbol, position and tag)
class GameObject
{
public:

	char Symbol; // How GameObject show in the map
	string tag; // For more justify searching in map
	Vector2 position; // position on map in Vector2

	/// <summary>
	/// Initialization
	/// </summary>
	/// <param name="position">position in Vector2</param>
	/// <param name="Symbol">Object symbol</param>
	/// <param name="tag">Tag</param>
	GameObject(Vector2 position, char Symbol, string tag = "") {
		this->position = position;
		this->Symbol = Symbol;
		this->tag = tag;
	}

	/// <summary>
	/// Initialization
	/// </summary>
	GameObject() {
		this->position = Vector2();
		this->Symbol = ' ';
		this->tag = "";
	}

private:

};

// Compare two GameObjects with "==" operator
bool operator == (GameObject left, GameObject right) {
	return (left.position == right.position && left.Symbol == right.Symbol && left.tag == right.tag) ? true : false;
}

// This class contains information about the game map (size, array of symbols), as well as an array of GameObjects used here
// Also functions for map manipulate
class GameMap
{
public:

	char defaultSymbol; //Standard background symbol

	/// <summary>
	/// Initialization
	/// </summary>
	/// <param name="size">Map size in Vector2</param>
	/// <param name="defaultSymbol">Standard symbol (for background)</param>
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

	/// <summary>
	/// Add GameObject to map
	/// </summary>
	/// <param name="gameObject">GameObject pointer</param>
	void addGameObject(GameObject* gameObject) {
		GameObjects.push_back(gameObject);
	}
	
	/// <summary>
	/// Delete GameObject from map
	/// </summary>
	/// <param name="id">ID</param>
	void deleteGameObjectById(int id) {
		GameObjects.erase(GameObjects.begin() + id);
	}

	/// <summary>
	/// Delete GameObject with current pointer
	/// </summary>
	/// <param name="gameObject">GameObject pointer</param>
	void deleteGameObject(GameObject* gameObject) {
		for (int i = 0; i < (int)GameObjects.size(); i++)
		{
			if (gameObject == GameObjects[i]) { GameObjects.erase(GameObjects.begin() + i); break; }
		}
	}

	/// <summary>
	/// This func drawing map from symbols on console window
	/// </summary>
	void draw() {

		for (int y = 0; y < size.y; y++)
		{
			for (int x = 0; x < size.x; x++)
			{
				Map[y][x] = defaultSymbol;
			}
		}

		for (int i = 0; i < (int)GameObjects.size(); i++)
		{
			if ((*GameObjects[i]).position.x > -1 && (*GameObjects[i]).position.y > -1
				&& (*GameObjects[i]).position.x < size.x && (*GameObjects[i]).position.y < size.y) {
				Map[(*GameObjects[i]).position.y][(*GameObjects[i]).position.x] = (*GameObjects[i]).Symbol;
			}
			else {
				cout << "GameObject[" << (*GameObjects[i]).Symbol << ", " << (*GameObjects[i]).tag << "] - out of map area!" << endl;
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
	
	/// <summary>
	/// GameObject search
	/// </summary>
	/// <param name="pos">position of Object (in Vector2)</param>
	/// <param name="showWarning">Show message that GameObject is not exist?</param>
	/// <returns>GameObject pointer in current position</returns>
	GameObject* getGameObjectByMapPosition(Vector2 pos, bool showWarning = true) {
		GameObject* obj = new GameObject(Vector2(), ' ', "");

		for(int i = 0; i < (int)GameObjects.size(); i++)
		{
			if ((*GameObjects[i]).position == pos) { obj = GameObjects[i]; break; }
		}

		if ((*obj).tag == "" && showWarning) cout << "GameObject no found!" << endl;
			
		return obj;
	}

	/// <summary>
	/// GameObject search
	/// </summary>
	/// <param name="tag">Tag of GameObjects</param>
	/// <param name="showWarning">Show message that GameObject is not exist?</param>
	/// <returns>GameObject pointer with this tag</returns>
	GameObject* getGameObjectByTag(string tag, bool showWarning = true) {
		GameObject* obj = new GameObject(Vector2(), ' ', "");

		for (int i = 0; i < (int)GameObjects.size(); i++)
		{
			if ((*GameObjects[i]).tag == tag) { obj = GameObjects[i]; break; }
		}

		if ((*obj).tag == "" && showWarning) cout << "GameObject no found!" << endl;

		return obj;
	}

	/// <summary>
	/// GameObjects search
	/// </summary>
	/// <param name="pos">Position of GameObjects (in Vector2)</param>
	/// <returns>Dynamic array (vector) of GameoObject pointers</returns>
	vector<GameObject*> getGameObjectsByMapPosition(Vector2 pos) {
		vector<GameObject*> objs;

		for (int i = 0; i < (int)GameObjects.size(); i++)
		{
			if ((*GameObjects[i]).position == pos) objs.push_back(GameObjects[i]);
		}

		return objs;
	}

	/// <summary>
	/// GameObjects search
	/// </summary>
	/// <param name="tag">Tag of GameObjects</param>
	/// <returns>Dynamic array (vector) of GameObject pointers</returns>
	vector<GameObject*> getGameObjectsByTag(string tag) {
		vector<GameObject*> objs;

		for (int i = 0; i < (int)GameObjects.size(); i++)
		{
			if ((*GameObjects[i]).tag == tag) objs.push_back(GameObjects[i]);
		}

		return objs;
	}

	/// <summary>
	/// GameObject search
	/// </summary>
	/// <param name="id">ID</param>
	/// <returns>GameObject pointer with this id</returns>
	GameObject* getGameObjectById(int id) {
		return GameObjects[id];
	}

private:

	vector<GameObject*> GameObjects; // Array of GameObjects
	vector<vector<char>> Map; // Char matrix
	Vector2 size; // map size

};
