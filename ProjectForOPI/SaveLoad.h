#pragma once
#include <iostream>
#include <fstream>
#include "Vars.h"
using namespace std;
using namespace Game;

void Save() {
	fstream save;

	save.open("Save.txt",fstream::out);

	if (!save.is_open()) {
		cout << "Error";
	}
	else {
		save.write(reinterpret_cast<char*>(&MaxHeal), sizeof(int));
		save.write(reinterpret_cast<char*>(&MaxStamina), sizeof(int));
		save.write(reinterpret_cast<char*>(&Heal), sizeof(int));
		save.write(reinterpret_cast<char*>(&Damage), sizeof(int));
		save.write(reinterpret_cast<char*>(&Armor), sizeof(int));
		save.write(reinterpret_cast<char*>(&MapId), sizeof(int));
	}
	save.close();
}
void Load() {
	fstream load;

	load.open("Save.txt",fstream::in);

	if (!load.is_open()) {
		cout << "Error";
	}
	else {
		load.read(reinterpret_cast<char*>(&MaxHeal), sizeof(int));
		load.read(reinterpret_cast<char*>(&MaxStamina), sizeof(int));
		load.read(reinterpret_cast<char*>(&Heal), sizeof(int));
		load.read(reinterpret_cast<char*>(&Damage), sizeof(int));
		load.read(reinterpret_cast<char*>(&Armor), sizeof(int));
		load.read(reinterpret_cast<char*>(&MapId), sizeof(int));

		switch (MapId) // For start position
		{
		case 0:
			Player.position = Vector2(23, 11);
			break;
		case 1:
			Player.position = Vector2(46, 23);
			break;
		case 2:
			Player.position = Vector2(1, 1);
			break;
		case 3:
			Player.position = Vector2(1, 4);
			break;
		case 4:
			Player.position = Vector2(1, 7);
			break;
		}

		LoadMap(&MainMap, MapId);
	}

	load.close();
}