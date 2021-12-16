#include <iostream>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"

using namespace std;

GameMap MainMap(Vector2(10, 6), '.');

int main() {
	setlocale(LC_ALL, "ru");

	int Key;

	GameObject Player = GameObject(Vector2(5, 2), 'P', "Player");

	GameObject One = GameObject(Vector2(0, 0), 'F', "Test");
	GameObject Two = GameObject(Vector2(9, 0), 'F', "Test");

	MainMap.addGameObject(new GameObject(Vector2(0, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(1, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(2, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(3, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(4, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(5, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(6, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(7, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(8, 5), '#', "Wall"));
	MainMap.addGameObject(new GameObject(Vector2(9, 5), '#', "Wall"));
	MainMap.addGameObject(&One);
	MainMap.addGameObject(&Two);
	MainMap.addGameObject(&Player);

	while (true)
	{
		MainMap.draw();

		Key = _getch();

		switch (Key)
		{
		case 72:
			Player.position.y--;
			break;
		case 80:
			Player.position.y++;
			break;
		case 77:
			Player.position.x++;
			break;
		case 75:
			Player.position.x--;
			break;
		case '1':
			MainMap.deleteGameObject(&One);
			break;
		case '2':
			MainMap.deleteGameObject(&Two);
			break;
		case 'F':
			vector<GameObject*> Walls = MainMap.getGameObjectsByTag("Wall");
			for (int i = 0; i < (int)Walls.size(); i++) MainMap.deleteGameObject(Walls[i]);
			break;
		}

		system("CLS");
	}

	return 0;
}