#pragma once
#include <iostream>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "FightSystem.h"
#include "Vars.h"
#include "Compontent.h"

using namespace CE;
using namespace std;

namespace Game {
	
	void testEvent() {
		system("cls");

		cout << "Event is work!!!" << endl;

		
		system("pause");
		system("cls");
	}

	void EventDumbbell() {

		system("cls");

		cout << "You get dumbbells. Your damage increased by 50" << endl;
		Damage = Damage + 50;

		system("pause");
	}

	void EventÑostume() {

		system("cls");

		cout << "You get BDSM costume. You get 20 max armor " << endl;
		Armor = Armor + 20;
		MaxArmor = MaxArmor + 20;

		system("pause");
	}

	void EventCumpot() {

		system("cls");

		cout << "You drink cumpot. You get max heal 500" << endl;
		Heal = Heal + 500;
		MaxHeal = MaxHeal + 500;

		system("pause");
	}

	void EventWhip() {

		system("cls");

		cout << "You get whip. Your damage increased by 100" << endl;
		Damage = Damage + 100;

		system("pause");
	}

	void EventUnit() {
		GameObject* object = Collision::Overlap(&MainMap, &Player);

		if ((*object).type == ObjectType::action) {
			if ((*object).tag == "Dumbbell") EventDumbbell();
			if ((*object).tag == "Cumpot") EventCumpot();
			if ((*object).tag == "Costumes") EventÑostume();
			if ((*object).tag == "test") testEvent();
			if ((*object).tag == "Whip") EventWhip();
			if ((*object).tag == "Trainer") /*EventTrainer()*/;

			MainMap.deleteGameObject(object);
		}


	}
}