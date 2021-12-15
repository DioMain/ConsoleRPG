#include <iostream>
#include <time.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"

using namespace std;

int main() {
	GameMap test(Vector2(5, 5), GameObject('.', "Floor"));

	test.draw();

	cout << test.getGameObjectByMapPosition(Vector2(0, 0)).tag << endl;
}