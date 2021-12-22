#pragma once
#include <vector>
#include <string>
#include "iostream"
#include "fstream"
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
			//save << Heal;
			//save << Armor;
			//save << Damage;
			//save << MapId;

			save.write(reinterpret_cast<char*>(&Heal), sizeof(int));
			save.write(reinterpret_cast<char*>(&Armor), sizeof(int));
			save.write(reinterpret_cast<char*>(&Damage), sizeof(int));
			save.write(reinterpret_cast<char*>(&MapId), sizeof(int));
		}
		save.close();

}
void Load() {
	fstream load;

	//char* buffer = new char[100];

	load.open("Save.txt",fstream::in);
	if (!load.is_open()) {
		cout << "Error";
	}
	else {
		load.read(reinterpret_cast<char*>(&Heal), sizeof(int));
		load.read(reinterpret_cast<char*>(&Armor), sizeof(int));
		load.read(reinterpret_cast<char*>(&Damage), sizeof(int));
		load.read(reinterpret_cast<char*>(&MapId), sizeof(int));

		//cout << Heal << endl << Armor << ;

		system("pause");

		LoadMap(&MainMap, MapId);
	}
	load.close();

	
}