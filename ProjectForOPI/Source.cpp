#include <iostream>
#include <time.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	GameMap testMap = GameMap(Vector2(10, 10), '.');

	GameObject obj = GameObject(Vector2(0, 0), '#', "first");

	testMap.addGameObject(&obj);
	testMap.addGameObject(new GameObject(Vector2(1, 1), '/', "second"));

	testMap.draw();

	cout << "X: " << (*testMap.getGameObjectByTag("first")).position.x << endl;
	cout << "Y: " << (*testMap.getGameObjectByTag("first")).position.y << endl;

	(*testMap.getGameObjectById(0)).position.y++;
	
	testMap.deleteGameObjectById(1);

	cout << "X: " << obj.position.x << endl;
	cout << "Y: " << obj.position.y << endl;

	testMap.draw();
}