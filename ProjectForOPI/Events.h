#pragma once
#include <iostream>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
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

		cout << "Let's go fight!!!" << endl;

		system("pause");
	}

	void EventBALL() {


		cout << "\nYou get dumbbells. Your damage increased by 5" << endl;
		
		system("pause");
		system("cls");
	}

	void EventUnit() {
		GameObject* object = Collision::Overlap(&MainMap, &Player);

		if ((*object).type == ObjectType::action) {
			if ((*object).tag == "BALL") EventBALL();
			if ((*object).tag == "test") testEvent();
			else if ((*object).tag == "F") EventF();

			MainMap.deleteGameObject(object);
		}


	}
}