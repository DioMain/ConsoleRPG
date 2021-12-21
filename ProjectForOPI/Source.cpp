#include <iostream>
#include <conio.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"
#include "Physics.h"
#include "Events.h"
#include "Maps.h"

using namespace std;
using namespace CE;
using namespace Game;

GameMap MainMap; // CURRENT LOAD MAP //

int Key = 0;
int Hunger = 100;
int Score = 0;

bool CandyIsGenerate = false;
bool IsLive = true;
bool NewLevel = false;

GameObject Player = GameObject(Vector2(5, 2), 'P', "Player");
GameObject Candy(Vector2(), 'C', "Candy");

CollisionDirection WallDir(None);

int main() {

	///////////PRELOAD///////////

	setlocale(LC_ALL, "ru");
	srand((int)time(0));
	
	MainMap = StartMap(&Player, &Candy);

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

		if (Hunger > 150 && !NewLevel) {
			MainMap = Game::EndMap(&Player, &Candy);
			NewLevel = true;
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