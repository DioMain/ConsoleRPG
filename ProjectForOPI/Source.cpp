#include <iostream>
#include <time.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	GameMap testMap = GameMap(Vector2(10, 10), '.');

	testMap.addGameObject(GameObject(Vector2(0, 0), '#', "first"));
	testMap.addGameObject(GameObject(Vector2(1, 1), '/', "second"));

	testMap.draw();

	cout << endl;
	//ÏÈÄÎÐ
	testMap.deleteGameObjectById(0);

	testMap.draw();
}