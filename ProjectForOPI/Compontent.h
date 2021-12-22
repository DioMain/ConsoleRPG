#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "DefaultMath.h"

using namespace std;

namespace CE {
	class Enemy
	{
	public:
		int health;
		int armor;
		int attack;

		string name;
		string discription;

		Enemy(int health, int armor, int attack, string name, string discription = "") {
			this->health = health;
			this->armor = armor;
			this->attack = attack;
			this->discription = discription;
			this->name = name;
		}

		Enemy() {
			this->health = 0;
			this->armor = 0;
			this->attack = 0;
			this->discription = "";
			this->name = "";
		}

	private:

	};

	enum ObjectType
	{
		deffault,
		wall,
		action
	};

	// This class contains information about the game object (Symbol, position and tag)
	class GameObject
	{
	public:

		char Symbol; // How GameObject show in the map
		string tag; // For more justify searching in map
		Vector2 position; // position on map in Vector2
		ObjectType type; // type of GameObject

		/// <summary>
		/// Initialization
		/// </summary>
		/// <param name="position">position in Vector2</param>
		/// <param name="Symbol">Object symbol</param>
		/// <param name="tag">Tag</param>
		GameObject(Vector2 position, char Symbol, string tag = "", ObjectType type = ObjectType::deffault) {
			this->position = position;
			this->Symbol = Symbol;
			this->tag = tag;
			this->type = type;
		}

		/// <summary>
		/// Initialization
		/// </summary>
		GameObject() {
			this->position = Vector2();
			this->Symbol = ' ';
			this->tag = "";
			this->type = ObjectType(deffault);
		}

	private:

	};

	// Compare two GameObjects with "==" operator
	bool operator == (GameObject left, GameObject right) {
		return (left.position == right.position && left.Symbol == right.Symbol && left.tag == right.tag && left.type == right.type) ? true : false;
	}
}