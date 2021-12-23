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
#include "SaveLoad.h"

using namespace CE;
using namespace std;

namespace Game {
	
	void EventLucky() {
		system("cls");

		cout << "You drink unknown liquid. You ";
		int ran = (rand() % 5) + 1;
		switch (ran) {
			case 1: { cout << "get damage 300\n"; Heal = Heal - 300;} break;
			case 2: { cout << "lose all armor\n"; Armor = 0; } break;
			case 3: { cout << "are became very strong. You get 300 damage. Your Damege: "; Damage = Damage + 300; 
					cout << Damage << endl; } break;
			case 4: { cout << "are very unlucky. You poisoned and you have only 1 Heal\n"; Heal = 1; } break;
			case 5: { cout << "feel great. Your max stamina has increased by 10\n"; MaxStamina = 20; } break;
			case 6: {
				int i = 1;
				char Key = 0;
				cout << "sleep. You will sleep 10 steps. Press F to sleep\n";
				while (i <= 10){
					Key = _getch();
					if (Key == 'F' || Key == 'f') {
						cout << "Step " << i << endl;
					i++;
					}
				}
				break;
			}
		}
		
		system("pause");
		system("cls");
	}

	void EventDumbbell() {

		system("cls");

		cout << "You get dumbbells. Your Damage increased by 50" << endl;
		Damage = Damage + 50;

		Sleep(500);

		system("pause");
		system("cls");
	}

	void EventCostume() {

		system("cls");

		cout << "You get BDSM Costume. You get 20 Armor points and 10 Max Stamina point" << endl;
		Armor += 20;
		MaxStamina += 10;


		Sleep(500);

		system("pause");
		system("cls");
	}

	void EventCumpot() {

		system("cls");

		cout << "You drink cumpot. You get Heal 500" << endl;
		Heal = Heal + 500;


		Sleep(500);

		system("pause");
		system("cls");
	}

	void EventWhip() {

		system("cls");

		cout << "You get whip. Your Damage increased by 100" << endl;
		Damage = Damage + 100;

		Sleep(500);

		system("pause");
		system("cls");
	}

	void EventTrain() {

		system("cls");

		cout << "You have entered the trainer. You will train 5 steps and your Damage increased by 20 . Press F to train" << endl;
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
		cout << "Your Max Stamina increased by 5: ";
		MaxStamina += 5;

		Sleep(500);

		system("pause");
		system("cls");
	}

	void EventToShMap() {
		system("cls");

		Player.position = Vector2(1, 1);

		LoadMap(&MainMap, 1);

		Save();
	}

	void EventToDimasMap() {
		system("cls");

		Player.position = Vector2(1, 4);

		LoadMap(&MainMap, 2);

		Save();
	}

	void EventTroll() {
		system("cls");

		cout << "Nothing"<< endl;

		system("pause");
		system("cls");
	}

	void EventToILMap() {
		system("cls");

		Player.position = Vector2(46, 23);

		LoadMap(&MainMap, 2);

		Save();
	}

	void TestBattle() {
		Fight(Enemys[1]);
	}

	void EventUnit() {
		GameObject* object = Collision::Overlap(&MainMap, &Player);
		if ((*object).type == ObjectType::action) {
			if ((*object).tag == "Lucky") EventLucky();
			if ((*object).tag == "Dumbbell") EventDumbbell();
			if ((*object).tag == "Costumes") EventCostume();
			if ((*object).tag == "Cumpot") EventCumpot();
			if ((*object).tag == "Whip") EventWhip();
			if ((*object).tag == "Train") EventTrain();
			if ((*object).tag == "ToMyMap") EventToShMap();
			if ((*object).tag == "ToDimas") EventToDimasMap();
			if ((*object).tag == "None") EventTroll();
			if ((*object).tag == "ToNextMap") EventToILMap();
			if ((*object).tag == "TestB") TestBattle();

			MainMap.deleteGameObject(object);
		}
	}
}