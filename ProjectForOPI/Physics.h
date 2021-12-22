#pragma once
#include <iostream>
#include <vector>
#include "GraphicEngine.h"

using namespace std;

namespace CE {

	// Collision direction
	enum CollisionDirection
	{
		None,
		Into,
		Right,
		Left,
		Up,
		Down
	};

	// Class which contains function for work with some collisions
	class Collision
	{
	public:

		static CollisionDirection GetColision(GameObject main, GameObject comparable) {
			if (main.position == comparable.position) return CollisionDirection(Into);
			else if (main.position.y - 1 == comparable.position.y && main.position.x == comparable.position.x) return CollisionDirection(Up);
			else if (main.position.y + 1 == comparable.position.y && main.position.x == comparable.position.x) return CollisionDirection(Down);
			else if (main.position.y == comparable.position.y && main.position.x + 1 == comparable.position.x) return CollisionDirection(Right);
			else if (main.position.y == comparable.position.y && main.position.x - 1 == comparable.position.x) return CollisionDirection(Left);
			else return CollisionDirection(None);
		}

		static CollisionDirection GetColisionByTag(GameMap* mapPointer, GameObject* objectPointer, string colisionTag) {
			vector<GameObject*> objs = (*mapPointer).getGameObjectsByTag(colisionTag);

			CollisionDirection CD(None);

			for (int i = 0; i < (int)objs.size(); i++)
			{
				if (GetColision(*objectPointer, *objs[i]) != CollisionDirection::None) {
					CD = GetColision(*objectPointer, *objs[i]);
					break;
				}
			}

			return CD;
		}

		static bool NearDirection(GameMap* mapPointer, GameObject* objectPointer, CollisionDirection direction, string colisionTag) {
			vector<GameObject*> objs = (*mapPointer).getGameObjectsByTag(colisionTag);

			for (int i = 0; i < (int)objs.size(); i++)
			{
				if (GetColision(*objectPointer, *objs[i]) == direction) return true;
			}

			return false;
		}

		static bool Overlap(GameObject first, GameObject second) {
			if (first.position == second.position) return true;
			else return false;
		}
		
		static GameObject* Overlap(GameMap* mapPointer, GameObject* target) {
			GameObject* obj = new GameObject(Vector2(), ' ');

			for (int i = 0; i < (*mapPointer).getGameObjectsCount(); i++)
			{
				if ((*target).position == (*(*mapPointer).getGameObjectById(i)).position)
					return (*mapPointer).getGameObjectById(i);
			}

			return obj;
		}

		static bool OverlapWithTag(GameMap* mapPointer, GameObject* objectPointer, string colisionTag) {
			vector<GameObject*> objs = (*mapPointer).getGameObjectsByTag(colisionTag);

			for (int i = 0; i < (int)objs.size(); i++)
			{
				if ((*objectPointer).position == (*objs[i]).position) return true;
			}

			return false;
		}

	};
}
