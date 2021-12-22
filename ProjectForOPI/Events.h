#pragma once
#include <iostream>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "FightSystem.h"
#include "Vars.h"
#include "Compontent.h"
#include "GameLogic.h"
#include "Maps.h"

using namespace CE;
using namespace std;

namespace Game {

	void EventDumbbell() {

		system("cls");

		cout << "You get dumbbells. Your damage increased by 50" << endl;
		Damage = Damage + 50;

		system("pause");
		system("cls");
	}

	void EventCostume() {

		system("cls");

		cout << "You get BDSM costume. You get 20 max armor " << endl;
		Armor = Armor + 20;
		MaxArmor = MaxArmor + 20;

		system("pause");
		system("cls");
	}

	void EventCumpot() {

		system("cls");

		cout << "You drink cumpot. You get max heal 500" << endl;
		Heal = Heal + 500;
		MaxHeal = MaxHeal + 500;

		system("pause");
		system("cls");
	}

	void EventWhip() {

		system("cls");

		cout << "You get whip. Your damage increased by 100" << endl;
		Damage = Damage + 100;

		system("pause");
		system("cls");
	}

	void EventTrain() {

		system("cls");

		cout << "You have entered the trainer. You will train 5 steps and your damage increased by 20 . Press F to train" << endl;
		int i = 1;
		char Key = 0;
		while(i <= 5) {
			Key = _getch();
			if (Key == 'F' || Key == 'f') {
				cout << "Step " << i << ": " << Damage << endl;
				Damage = Damage + 20;
				i++;
			}
		}
		cout << "Your damage: " << Damage << endl;

		system("pause");
		system("cls");
	}

	void EventToMyMap() {
		system("cls");

		LoadMap(&MainMap, 1);
	}
	void EventTroll() {
		system("cls");

		cout << "Nothing"<< endl;

		system("pause");
		system("cls");
	}
	void EventUnit() {
		GameObject* object = Collision::Overlap(&MainMap, &Player);

		if ((*object).type == ObjectType::action) {
			if ((*object).tag == "Dumbbell") EventDumbbell();
			if ((*object).tag == "Cumpot") EventCumpot();
			if ((*object).tag == "Costumes") EventCostume();
			if ((*object).tag == "Whip") EventWhip();
			if ((*object).tag == "Train") EventTrain();
			if ((*object).tag == "ToMyMap") EventToMyMap();

			MainMap.deleteGameObject(object);
		}
	}
}