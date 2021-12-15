#pragma once
#include <vector>
#include <string>
#include "DefaultMath.h"

using namespace std;

class GameMap
{
public:

	char defaultSymbol;

	GameMap(Vector2 size, char defaultSymbol) {
		this->size = size;
		this->defaultSymbol = defaultSymbol;


	}
	
private:

	vector<vector<char>> charMap;
	Vector2 size;

	void RESIZE() {
		
	}

};

class CharObject
{
public:
	
	char Symbol;
	string tag;

private:

};