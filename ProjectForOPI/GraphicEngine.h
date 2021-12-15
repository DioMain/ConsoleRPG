#pragma once
#include <vector>
#include <string>
#include "DefaultMath.h"

using namespace std;

// This class contains information about the game object (Symbol, position and tag) test
class GameObject
{
public:

	char Symbol; // How GameObject show in the map
	string tag; // For more justify searching in map
	Vector2 position; // position on map in Vector2

	/// <summary>
	/// Initialization : Èíèöèàëèçàöèÿ
	/// </summary>
	/// <param name="position">Ïîçèöèÿ íà êàðòå â Vector2</param>
	/// <param name="Symbol">Ñèìâîë îáúåêòà</param>
	/// <param name="tag">Òåã</param>
	GameObject(Vector2 position, char Symbol, string tag = "") {
		this->position = position;
		this->Symbol = Symbol;
		this->tag = tag;
	}

	/// <summary>
	/// Initialization : Èíèöèàëèçàöèÿ
	/// </summary>
	GameObject() {
		this->position = Vector2();
		this->Symbol = ' ';
		this->tag = "";
	}

private:

};

// This class contains information about the game map (size, array of symbols), as well as an array of GameObjects used here
// Also functions for map manipulate
class GameMap
{
public:

	char defaultSymbol; //Standard background symbol

	/// <summary>
	/// Initialization : Èíèöèàëèçàöèÿ
	/// </summary>
	/// <param name="size">Ðàçìåð êàðòû â Vector2</param>
	/// <param name="defaultSymbol">Ñòàíäàðòíûé ñèìâîë (äëÿ çàäíåãî ôîíà)</param>
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
	/// Add GameObject to map : Äîáàâèòü GameObject â êàðòó
	/// </summary>
	/// <param name="gameObject">Èãðîâîé îáúåêò</param>
	void addGameObject(GameObject gameObject) {
		GameObjects.push_back(gameObject);
	}
	
	/// <summary>
	/// Delete GameObject from map : Óäàëÿåò GameObject èç êàðòû
	/// </summary>
	/// <param name="id">Èäåíòèôèêàòîð</param>
	void deleteGameObjectById(int id) {
		GameObjects.erase(GameObjects.begin() + id);
	}

	/// <summary>
	/// This func drawing map from symbols on console window : Ýòà ôóíêöèÿ ðèñîâàíèÿ êàðòû èç ñèìâîëîâ â îêíå êîíñîëè
	/// </summary>
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
	
	/// <summary>
	/// GameObject search : Ïîèñê GameObject-òà
	/// </summary>
	/// <param name="pos">Ïîçèöèÿ GameObject-òà (Â Vector2)</param>
	/// <param name="showWarning">Âûâîäèòü ñîîáùåíèå åñëè íè÷åãî íå íàéäåíî?</param>
	/// <returns>GameObject in current position : GameObject â ýòîé ïîçèöèè</returns>
	GameObject getGameObjectByMapPosition(Vector2 pos, bool showWarning = true) {
		GameObject obj(Vector2(), ' ', "null");

		for(int i = 0; i < GameObjects.size(); i++)
		{
			if (GameObjects[i].position == pos) { obj = GameObjects[i]; break; }
		}

		if (obj.tag == "null" && showWarning) cout << "GameObject no found!" << endl;
			
		return obj;
	}

	/// <summary>
	/// GameObject search : Ïîèñê GameObject
	/// </summary>
	/// <param name="tag">Òåã GameObject-òà</param>
	/// <param name="showWarning">Âûâîäèòü ñîîáùåíèå åñëè íè÷åãî íå íàéäåíî?</param>
	/// <returns>GameObject with this tag : GameObject ñ ýòèì òåãîì</returns>
	GameObject getGameObjectByTag(string tag, bool showWarning = true) {
		GameObject obj(Vector2(), ' ', "null");

		for (int i = 0; i < GameObjects.size(); i++)
		{
			if (GameObjects[i].tag == tag) { obj = GameObjects[i]; break; }
		}

		if (obj.tag == "null" && showWarning) cout << "GameObject no found!" << endl;

		return obj;
	}

	/// <summary>
	/// GameObjects search : Ïîèñê GameObject-òîâ
	/// </summary>
	/// <param name="pos">Ïîçèöèÿ GameObject-òîâ (Â Vector2)</param>
	/// <returns>Dynamic array (vector) from GameObjects : Äèíàìè÷åñêèé ìàññèâ (vector) èç GameObject-òîâ</returns>
	vector<GameObject> getGameObjectsByMapPosition(Vector2 pos) {
		vector<GameObject> objs;

		for (int i = 0; i < GameObjects.size(); i++)
		{
			if (GameObjects[i].position == pos) objs.push_back(GameObjects[i]);
		}

		return objs;
	}

	/// <summary>
	/// GameObjects search : Ïîèñê GameObject-òîâ
	/// </summary>
	/// <param name="tag">Òåã GameObject-òîâ</param>
	/// <returns>Dynamic array (vector) from GameObjects : Äèíàìè÷åñêèé ìàññèâ (vector) èç GameObject-òîâ</returns>
	vector<GameObject> getGameObjectsByTag(string tag) {
		vector<GameObject> objs;

		for (int i = 0; i < GameObjects.size(); i++)
		{
			if (GameObjects[i].tag == tag) objs.push_back(GameObjects[i]);
		}

		return objs;
	}

	GameObject getGameObjectById(int id) {
		return GameObjects[id];
	}

private:

	vector<GameObject> GameObjects; // Array of GameObjects
	vector<vector<char>> Map; // Char matrix
	Vector2 size; // map size

};
