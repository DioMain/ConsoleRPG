#include <iostream>
#include <time.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	//Тестируем


	GameMap testMap(Vector2(10, 5), '.');

	testMap.addGameObject(GameObject(Vector2(0, 0), '#', "first"));
	testMap.addGameObject(GameObject(Vector2(1, 1), '/', "second"));

	testMap.draw();

	cout << endl;
	//ПИДОР
	testMap.deleteGameObjectById(0);

	testMap.draw();
}