#include <iostream>
#include <time.h>
#include "DefaultMath.h"
#include "GraphicEngine.h"

using namespace std;

int main() {
	Vector2 t1(2, 3);

	Vector2 t2(14, 4);

	Vector2 t3 = t1 + t2;

	int len = Vector2::Length(t3);

	cout << t3.x << " " << t3.y << endl << "length: " << len << endl;
	cout << "Angle t1, t2 = " << Vector2::Angle(t1, t2);
}