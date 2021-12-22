#pragma once
#include <iostream>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "FightSystem.h"
#include "Vars.h"

using namespace CE;
using namespace std;

namespace Game {
	
	void testEvent() {
		system("cls");

		cout << "Event is work!!!" << endl;

		system("pause");
	}
	
	void EventF() {
		system("cls");

		//cout << Enemys[0].name << endl << Enemys[0].health << endl << Enemys[0].armor << endl << Enemys[0].attack << endl 
		//	<< Enemys[0].discription << endl;

		system("pause");
	}

	void EventUnit() {
		GameObject* object = Collision::Overlap(&MainMap, &Player);

		if ((*object).type == ObjectType::action) {
			if ((*object).tag == "test") testEvent();
			else if ((*object).tag == "F") EventF();

			MainMap.deleteGameObject(object);
		}
	}
}