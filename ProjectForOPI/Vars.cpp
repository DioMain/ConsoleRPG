#include "Libs.h"

GameMap MainMap(Vector2(20, 10), ' '); // CURRENT LOAD MAP //

int Key = 0;
int Hunger = 100;
int Score = 0;

bool CandyIsGenerate = false;
bool IsLive = true;

GameObject Player = GameObject(Vector2(5, 2), 'P', "Player");
GameObject Candy(Vector2(), 'C', "Candy");


CollisionDirection WallDir(None);