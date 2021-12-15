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
	/// Initialization : Инициализация
	/// </summary>
	/// <param name="position">Позиция на карте в Vector2</param>
	/// <param name="Symbol">Символ объекта</param>
	/// <param name="tag">Тег</param>
	GameObject(Vector2 position, char Symbol, string tag = "") {
		this->position = position;
		this->Symbol = Symbol;
		this->tag = tag;
	}

	/// <summary>
	/// Initialization : Инициализация
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
	/// Initialization : Инициализация
	/// </summary>
	/// <param name="size">Размер карты в Vector2</param>
	/// <param name="defaultSymbol">Стандартный символ (для заднего фона)</param>
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
	/// Add GameObject to map : Добавить GameObject в карту
	/// </summary>
	/// <param name="gameObject">Игровой объект</param>
	void addGameObject(GameObject gameObject) {
		GameObjects.push_back(gameObject);
	}
	
	/// <summary>
	/// Delete GameObject from map : Удаляет GameObject из карты
	/// </summary>
	/// <param name="id">Идентификатор</param>
	void deleteGameObjectById(int id) {
		GameObjects.erase(GameObjects.begin() + id);
	}

	/// <summary>
	/// This func drawing map from symbols on console window : Эта функция рисования карты из символов в окне консоли
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
	/// GameObject search : Поиск GameObject-та
	/// </summary>
	/// <param name="pos">Позиция GameObject-та (В Vector2)</param>
	/// <param name="showWarning">Выводить сообщение если ничего не найдено?</param>
	/// <returns>GameObject in current position : GameObject в этой позиции</returns>
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
	/// GameObject search : Поиск GameObject
	/// </summary>
	/// <param name="tag">Тег GameObject-та</param>
	/// <param name="showWarning">Выводить сообщение если ничего не найдено?</param>
	/// <returns>GameObject with this tag : GameObject с этим тегом</returns>
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
	/// GameObjects search : Поиск GameObject-тов
	/// </summary>
	/// <param name="pos">Позиция GameObject-тов (В Vector2)</param>
	/// <returns>Dynamic array (vector) from GameObjects : Динамический массив (vector) из GameObject-тов</returns>
	vector<GameObject> getGameObjectsByMapPosition(Vector2 pos) {
		vector<GameObject> objs;

		for (int i = 0; i < GameObjects.size(); i++)
		{
			if (GameObjects[i].position == pos) objs.push_back(GameObjects[i]);
		}

		return objs;
	}

	/// <summary>
	/// GameObjects search : Поиск GameObject-тов
	/// </summary>
	/// <param name="tag">Тег GameObject-тов</param>
	/// <returns>Dynamic array (vector) from GameObjects : Динамический массив (vector) из GameObject-тов</returns>
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
