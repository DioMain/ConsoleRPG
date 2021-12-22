#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Vars.h"
#include "DefaultMath.h"
#include "Physics.h"
#include "GraphicEngine.h"
#include "Compontent.h"


using namespace CE;
using namespace std;

namespace Game {

	void crips()
	{
		Enemy BossOfTheGYM(5000, 150, 500, "BossOfTheGYM", "BossOfTheGYM - kind on the outside, cruel on the inside, who is always ready to back you up from behind");
		Enemy Trainer(1500, 50, 150, "Trainer", "If he is not paid, then he is very angry ...\nHe was not paid ...");

		Enemys.push_back(BossOfTheGYM);
		Enemys.push_back(Trainer);
	}

	void Fight() {
		system("cls");

		system("pause");

		system("cls");
	}

	
}