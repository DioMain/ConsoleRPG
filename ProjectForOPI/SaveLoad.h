#pragma once
#include "iostream"
#include "fstream"
#include "Vars.h"
using namespace std;
using namespace Game;
void Save() {
	ofstream save;
	save.open("Save.txt");
		if (!save.is_open()) {
			cout << "Error";
		}
		else {
			save << "\nHeath=" << Heal;
			save << "\nArmor=" << Armor;
			save << "\nDamage=" << Damage;
		}
		save.close();
}