#pragma once
#include <vector>
#include <string>
#include "DefaultMath.h"

using namespace std;

class GameMap
{
public:
	char defaultSymbol;

	GameMap() {

	}
	
private:
	vector<vector<char>> charMap;
	Vector2 size;

};

class CharObject
{
public:
	
	char Symbol;
	string tag;

private:

};