#pragma once
#include <iostream>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "FightSystem.h"
#include "Vars.h"
#include "Compontent.h"
#include "GameLogic.h"

using namespace CE;
using namespace std;

namespace Game {
	
	void EventLucky() {
		system("cls");

		cout << "You drink unknown liquid. You ";
		int ran = 5;
		switch (ran) {
			case 1: { cout << "get damage 300\n"; Heal = Heal - 300;} break;
			case 2: { cout << "get regeneration\n"; /*Regan = Regan = 10*/; } break;
			case 3: { cout << "lose all armor\n"; Armor = 0; } break;
			case 4: { cout << "are became very strong. You get 300 damage. Your Damege: "; Damage = Damage + 300; 
					cout << Damage << endl; } break;
			case 5: { cout << "are very unlucky. You poisoned and you have only 1 Heal\n"; Heal = 1; } break;
		}
		
		system("pause");
		system("cls");
	}

	void EventDumbbell() {

		system("cls");

		cout << "You get dumbbells. Your damage increased by 50" << endl;
		Damage = Damage + 50;
		cout << "You Damage: " << Damage << endl;

		system("pause");
		system("cls");
	}

	void EventÑostume() {

		system("cls");

		cout << "You get BDSM costume. You get 20 max armor " << endl;
		Armor = Armor + 20;
		MaxArmor = MaxArmor + 20;
		cout << "Your Max Armor: " << MaxArmor << endl;

		system("pause");
		system("cls");
	}

	void EventCumpot() {

		system("cls");

		cout << "You drink cumpot. You get max heal 500" << endl;
		Heal = Heal + 500;
		MaxHeal = MaxHeal + 500;
		cout << "Your Max Helth: " << MaxHeal << endl;

		system("pause");
		system("cls");
	}

	void EventWhip() {

		system("cls");

		cout << "You get whip. Your damage increased by 100" << endl;
		Damage = Damage + 100;
		cout << "Your Damage: " << Damage << endl;

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


	void EventUnit() {
		GameObject* object = Collision::Overlap(&MainMap, &Player);
		if ((*object).type == ObjectType::action) {
			if ((*object).tag == "Dumbbell") EventDumbbell();
			if ((*object).tag == "Cumpot") EventCumpot();
			if ((*object).tag == "Costumes") EventÑostume();
			if ((*object).tag == "test") EventLucky();
			if ((*object).tag == "Whip") EventWhip();
			if ((*object).tag == "Train") EventTrain();
			//if ((*object).tag == "RunTracker") EventRun();

			MainMap.deleteGameObject(object);
		}


	}
}