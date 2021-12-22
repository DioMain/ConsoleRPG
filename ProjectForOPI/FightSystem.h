#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Vars.h"
#include "DefaultMath.h"
#include "Physics.h"
#include "GraphicEngine.h"
#include "Compontent.h"


using namespace CE;
using namespace std;

namespace Game {

	void EnemysUnit()
	{
		Enemy BossOfTheGYM(5000, 150, 500, "BossOfTheGYM", "BossOfTheGYM - kind on the outside, cruel on the inside, who is always ready to back you up from behind");
		Enemy Trainer(500, 10, 50, "Trainer", "If he is not paid, then he is very angry ...\nHe was not paid ...");

		Enemys.push_back(BossOfTheGYM);
		Enemys.push_back(Trainer);
	}
	
	int GetDamage(int damage, int armor) {
		return (damage > armor) ? round((double)damage * (double)((double)((rand() % 50) + 75) / 100)) - armor : 0;
	}

	void Fight(Enemy enemy) {
		std::system("cls");

		cout << enemy.name << " attack you!" << endl;

		std::system("pause");
		std::system("cls");

		int key = 0;
		int choise = 0;
		int attackType = 0;

		int lastDamage = 0;

		int PlayerStamina = MaxStamina;

		while (true)
		{
			std::system("cls");
			
			cout << "<===============Enemy " << enemy.name << "================>" << endl;
			cout << "HEAL = " << enemy.health << endl;
			cout << "Last damage = " << lastDamage << endl << endl;

			cout << "<===============Player================>" << endl;
			cout << "Heal = " << Heal << endl;
			cout << "Stamina = " << PlayerStamina << endl << endl;

			switch (choise)
			{
			case 0:
				cout << ">>Fight" << endl
					<< "Stat" << endl
					<< "Rest" << endl;
				break;
			case 1:
				cout << "Fight" << endl
					<< ">>Stat" << endl
					<< "Rest" << endl;
				break;
			case 2:
				cout << "Fight" << endl
					<< "Stat" << endl
					<< ">>Rest" << endl;
				break;
			}

			key = _getch();

			if ((key == 'w' || key == 'W') && choise > 0) choise--;
			else if ((key == 's' || key == 'S') && choise < 2) choise++;
			else if (key == 13) {
				switch (choise)
				{
				case 0:
					while (true)
					{
						std::system("cls");

						cout << "Choise attack type :" << endl << endl;

						switch (attackType)
						{
						case 0:
							cout << ">>Hand" << endl
								<< "Leg" << endl
								<< "Cancel" << endl;
							break;
						case 1:
							cout << "Hand" << endl
								<< ">>Leg" << endl
								<< "Cancel" << endl;
							break;
						case 2:
							cout << "Hand" << endl
								<< "Leg" << endl
								<< ">>Cancel" << endl;
							break;
						}

						key = _getch();

						if ((key == 'w' || key == 'W') && attackType > 0) attackType--;
						else if ((key == 's' || key == 'S') && attackType < 2) attackType++;
						else if (key == 13) {
							if (attackType == 2) break;
							else {
								if (attackType == 0 && PlayerStamina > 0) { enemy.health -= GetDamage(Damage, enemy.armor); PlayerStamina -= 1; }
								else if (attackType == 0) { cout << "You dont have necessary stamina points!" << endl; system("pause"); }

								if (attackType == 1 && PlayerStamina > 2) { enemy.health -= round((double)GetDamage(Damage, enemy.armor) * 1.3); PlayerStamina -= 3; }
								else if (attackType == 1) { cout << "You dont have necessary stamina points!" << endl; system("pause"); }

								lastDamage = GetDamage(enemy.attack, Armor);

								Heal -= lastDamage;

								break;
							}
						}
					}
					break;
				case 1:
					std::system("cls");

					cout << enemy.name << endl;
					cout << "----------------------------------------------" << endl;
					cout << enemy.discription << endl << endl;

					cout << "Damage: " << enemy.attack << endl
						<< "Armor:" << enemy.armor << endl;

					std::system("pause");
					break;
				case 2:

					PlayerStamina += (PlayerStamina < MaxStamina) ? round((double)MaxStamina * 0.3) : 0;

					lastDamage = GetDamage(enemy.attack, Armor);

					Heal -= lastDamage;
					break;
				}
			}

			if (enemy.health <= 0) {
				system("cls");

				cout << "You winner!!!" << endl;

				system("pause");

				break;
			}
			if (Heal <= 0) break;
		}

		std::system("cls");
	}
}