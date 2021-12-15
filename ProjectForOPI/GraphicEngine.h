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
	/// Initialization : �������������
	/// </summary>
	/// <param name="position">������� �� ����� � Vector2</param>
	/// <param name="Symbol">������ �������</param>
	/// <param name="tag">���</param>
	GameObject(Vector2 position, char Symbol, string tag = "") {
		this->position = position;
		this->Symbol = Symbol;
		this->tag = tag;
	}

	/// <summary>
	/// Initialization : �������������
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
	/// Initialization : �������������
	/// </summary>
	/// <param name="size">������ ����� � Vector2</param>
	/// <param name="defaultSymbol">����������� ������ (��� ������� ����)</param>
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
	/// Add GameObject to map : �������� GameObject � �����
	/// </summary>
	/// <param name="gameObject">������� ������</param>
	void addGameObject(GameObject gameObject) {
		GameObjects.push_back(gameObject);
	}
	
	/// <summary>
	/// Delete GameObject from map : ������� GameObject �� �����
	/// </summary>
	/// <param name="id">�������������</param>
	void deleteGameObjectById(int id) {
		GameObjects.erase(GameObjects.begin() + id);
	}

	/// <summary>
	/// This func drawing map from symbols on console window : ��� ������� ��������� ����� �� �������� � ���� �������
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
	/// GameObject search : ����� GameObject-��
	/// </summary>
	/// <param name="pos">������� GameObject-�� (� Vector2)</param>
	/// <param name="showWarning">�������� ��������� ���� ������ �� �������?</param>
	/// <returns>GameObject in current position : GameObject � ���� �������</returns>
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
	/// GameObject search : ����� GameObject
	/// </summary>
	/// <param name="tag">��� GameObject-��</param>
	/// <param name="showWarning">�������� ��������� ���� ������ �� �������?</param>
	/// <returns>GameObject with this tag : GameObject � ���� �����</returns>
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
	/// GameObjects search : ����� GameObject-���
	/// </summary>
	/// <param name="pos">������� GameObject-��� (� Vector2)</param>
	/// <returns>Dynamic array (vector) from GameObjects : ������������ ������ (vector) �� GameObject-���</returns>
	vector<GameObject> getGameObjectsByMapPosition(Vector2 pos) {
		vector<GameObject> objs;

		for (int i = 0; i < GameObjects.size(); i++)
		{
			if (GameObjects[i].position == pos) objs.push_back(GameObjects[i]);
		}

		return objs;
	}

	/// <summary>
	/// GameObjects search : ����� GameObject-���
	/// </summary>
	/// <param name="tag">��� GameObject-���</param>
	/// <returns>Dynamic array (vector) from GameObjects : ������������ ������ (vector) �� GameObject-���</returns>
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
