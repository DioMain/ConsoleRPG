#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "DefaultMath.h"
#include "Physics.h"
#include "GraphicEngine.h"

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

	class MyClass
	{
	public:
		
		MyClass() {

		}

	private:

	};
}