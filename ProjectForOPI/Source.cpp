#include <iostream>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"

using namespace std;

///////////ONLY GLOBAL VARIABLES///////////

GameMap MainMap(Vector2(20, 10), ' '); // CURRENT LOAD MAP //

bool IsLive = true;

///////////ONLY GLOBAL VARIABLES///////////

int main() {

	///////////PRELOAD///////////

	setlocale(LC_ALL, "ru");
	srand((int)time(0));

	int Key = 0;
	int Hunger = 100;
	int Score = 0;

	bool CandyIsGenerate = false;

	CollisionDirection WallDir(None);

	GameObject Player = GameObject(Vector2(5, 2), 'P', "Player");
	GameObject Candy(Vector2(), 'C', "Candy");

	for (int y = 0; y < MainMap.getSize().y; y++) // WALL GENERATE //
	{
		for (int x = 0; x < MainMap.getSize().x; x++)
		{
			if (y == 0 || y == MainMap.getSize().y - 1) {
				MainMap.addGameObject(new GameObject(Vector2(x, y), '#', "Wall"));
			}
			else {
				MainMap.addGameObject(new GameObject(Vector2(0, y), '#', "Wall"));
				MainMap.addGameObject(new GameObject(Vector2(MainMap.getSize().x - 1, y), '#', "Wall"));
			}
		}
	}

	MainMap.addGameObject(&Player);
	MainMap.addGameObject(&Candy);
	
	///////////PRELOAD///////////

	while (IsLive) 
	{
		///////////BEFORE RENDER///////////

		std::system("CLS"); // CONSOLE CLEAR //

		if (!CandyIsGenerate) { // CANDY GENERATE //
			Candy.position = Vector2((rand() % (MainMap.getSize().x - 3)) + 1, (rand() % (MainMap.getSize().y - 3)) + 1);
			CandyIsGenerate = true;
		}

		cout << "Hunger: " << Hunger << ", Score: " << Score << endl << endl;

		///////////BEFORE RENDER///////////

		MainMap.Render(); // RENDER FUNCTION

		///////////AFTER RENDER///////////

		Key = _getch();

		switch (Key) // INPUT MANAGER //
		{
		case 'w':
			if (!Collision::NearDirection(&MainMap, &Player, CollisionDirection(Up), "Wall")) Player.position.y--;
			break;
		case 's':
			if (!Collision::NearDirection(&MainMap, &Player, CollisionDirection(Down), "Wall")) Player.position.y++;
			break;
		case 'd':
			if (!Collision::NearDirection(&MainMap, &Player, CollisionDirection(Right), "Wall")) Player.position.x++;
			break;
		case 'a':
			if (!Collision::NearDirection(&MainMap, &Player, CollisionDirection(Left), "Wall")) Player.position.x--;
			break;
		}

		if (Collision::Overlap(Player, Candy)) { // IF PLAYER PICK UP CANDY //
			Hunger += 25;
			CandyIsGenerate = false;
		}

		Hunger -= 3;
		Score++;

		IsLive = (Hunger > 0) ? true : false;

		///////////AFTER RENDER///////////
	}

	///////////PASTLOAD///////////

	std::system("CLS"); // CONSOLE CLEAR //

	cout << "YOUR IS DEAD!!!" << endl;
	cout << endl << "Score: " << Score << endl;

	std::system("pause"); // CONSOLE WAIT INPUT ANY KEY //

	return 0;
}