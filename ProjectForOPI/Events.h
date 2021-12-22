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
	
	void EventF() {
		system("cls");

		cout << Enemys[1].name << endl << Enemys[1].health << endl << Enemys[1].armor << endl << Enemys[1].attack << endl 
			<< Enemys[1].discription << endl;

		system("pause");
		system("cls");
	}

	void EventM() {
		system("cls");
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
			if ((*object).tag == "test") testEvent();
			else if ((*object).tag == "F") EventF();
			else if ((*object).tag == "nextlocate") EventM();
			else if ((*object).tag == "None") EventTroll();

			MainMap.deleteGameObject(object);
		}
	}
}