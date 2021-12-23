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
		Enemy BossOfTheGYM(2500, 75, 220, "BossOfTheGYM", "BossOfTheGYM - kind on the outside, cruel on the inside, who is always ready to back you up from behind");
		Enemy Trainer(500, 50, 100, "Trainer", "If he is not paid, then he is very angry ...\nHe was not paid ...");
		Enemy Security(850, 50, 110, "Security", "With its protein-filled nose, it feels your ass from far away");
		Enemy Manager(600, 50, 75, "Manager", "Takes tribute from new visitors, dislikes intruders, very much");
		Enemy Bodybuilder(1050, 30, 120, "Bodybuilder", "GYM Old, loves protein drinks and himself");
		Enemy Pimple(245, 10, 10, "pimple", "beginner, wants to show that he is the coolest, usually arrogant");

		Enemys.push_back(BossOfTheGYM);
		Enemys.push_back(Trainer);
		Enemys.push_back(Security);
		Enemys.push_back(Manager);
		Enemys.push_back(Bodybuilder);
		Enemys.push_back(Pimple);
	}
	
	int GetDamage(int damage, int armor) {
		return (damage > armor) ? round((double)damage * (double)((double)((rand() % 50) + 75) / 100)) - armor : 0;
	}

	void Fight(Enemy enemy) {
		std::system("cls");

		cout << enemy.name << " attack you!" << endl;

		Sleep(500);

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
			cout << "HEAL: " << enemy.health << endl << endl;

			if (lastDamage > 0) cout << "Damage done to you: " << lastDamage << endl << endl;

			cout << "<===============Player================>" << endl;
			cout << "HEAL: " << Heal << endl;
			cout << "STAMINA: " << PlayerStamina << endl << endl;

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

						int lastPlayerDamange = 0;

						if ((key == 'w' || key == 'W') && attackType > 0) attackType--;
						else if ((key == 's' || key == 'S') && attackType < 2) attackType++;
						else if (key == 13) {
							if (attackType == 2) break;
							else {
								system("cls");

								if (attackType == 0 && PlayerStamina > 0) { 
									lastPlayerDamange = GetDamage(Damage, enemy.armor); 
									enemy.health -= lastPlayerDamange;
									PlayerStamina -= 1;

									if (lastPlayerDamange > 0) cout << "You inflicted " << lastPlayerDamange << " of damage!" << endl << endl;
									else cout << "You are too weak to do damage!" << endl << endl;

									Sleep(250);

									system("pause");
								}
								else if (attackType == 0) { cout << "You dont have necessary stamina points!" << endl << endl;; Sleep(250); system("pause"); }

								if (attackType == 1 && PlayerStamina > 2) { 
									lastPlayerDamange = round((double)GetDamage(Damage, enemy.armor) * 1.3);
									enemy.health -= lastPlayerDamange;
									PlayerStamina -= 3; 

									if (lastPlayerDamange > 0) cout << "You inflicted " << lastPlayerDamange << " of damage!" << endl << endl;
									else cout << "You are too weak to do damage!" << endl << endl;

									Sleep(250);

									system("pause");
								}
								else if (attackType == 1) { cout << "You dont have necessary stamina points!" << endl << endl;; Sleep(250); system("pause"); }

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

				Sleep(500);

				system("pause");

				break;
			}
			if (Heal <= 0) break;
		}

		std::system("cls");
	}
}
