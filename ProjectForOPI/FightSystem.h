#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Vars.h"
#include "DefaultMath.h"
#include "Physics.h"
#include "GraphicEngine.h"



using namespace CE;
using namespace std;

namespace Game {

	class Vorag
	{
	public:
		int health;
		int armor;
		int attack;
		string name;
		string discription;

		Vorag(int health, int armor, int attack, string name, string discription = "") {
			this->health = health;
			this->armor = armor;
			this->attack = attack;
			this->discription = discription;
			this->name = name;

		}

		Vorag() {
			this->health = 0;
			this->armor = 0;
			this->attack = 0;
			this->discription = "";
			this->name = "";

		}
	private:
	};

	void crips()
	{
		Vorag BossOfTheGYM(5000, 150, 500, "BossOfTheGYM", "BossOfTheGYM - kind on the outside, cruel on the inside, who is always ready to back you up from behind");
		Vorag Trainer(1500, 50, 150, "Trainer", "If he is not paid, then he is very angry ...\nHe was not paid ...");

		/*Enemys.push_back(BossOfTheGYM);
		Enemys.push_back(Trainer);*/
	}

	void Fight() {
		system("cls");

		system("pause");

		system("cls");
	}

	
}