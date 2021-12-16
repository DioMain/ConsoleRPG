#include <iostream>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"

using namespace std;

GameMap MainMap(Vector2(10, 6), '.');

int main() {
	setlocale(LC_ALL, "ru");

	char Key;

	GameObject Player = GameObject(Vector2(5, 2), 'P', "Player");

	MainMap.addGameObject(new GameObject(Vector2(0, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(1, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(2, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(3, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(4, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(5, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(6, 5), '#', "Wall"));
	MainMap.addGameObject(&Player);

	while (true)
	{
		MainMap.draw();

		Key = _getch();

		switch (Key)
		{
		case 'w':
			Player.position.y--;
			break;
		case 's':
			Player.position.y++;
			break;
		case 'd':
			Player.position.x++;
			break;
		case 'a':
			Player.position.x--;
			break;
		}

		system("CLS");
	}
}