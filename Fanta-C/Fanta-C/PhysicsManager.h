#ifndef _PHYSICS_MANAGER_H
#define _PHYSICS_MANAGER_H

// System Headers
#include <vector>

// My Headers
#include "CollisionManager.h"

class PhysicsManager
{
	class CollisionManager collisionManager;
public:
	// Update
	void Update(std::vector<class ObjectManager*>* collidableObjects);
};

#endif