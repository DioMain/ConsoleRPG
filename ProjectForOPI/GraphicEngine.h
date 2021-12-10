#pragma once
#include <vector>
#include <string>
#include "DefaultMath.h"

class GameMap
{
public:
	char defaultSymbol;
	
private:
	//Vector<Char>
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