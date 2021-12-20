#include "Libs.h"
#include "Vars.cpp"

using namespace std;

int main() {

	///////////PRELOAD///////////

	setlocale(LC_ALL, "ru");
	srand((int)time(0));

	PreLoad();
	
	///////////PRELOAD///////////

	while (IsLive) 
	{
		///////////BEFORE RENDER///////////

		PreRenders();

		///////////BEFORE RENDER///////////

		MainMap.Render(); // RENDER FUNCTION

		///////////AFTER RENDER///////////

		PastRender();

		///////////AFTER RENDER///////////
	}

	///////////PASTLOAD///////////

	PastLoad();

	return 0;
}