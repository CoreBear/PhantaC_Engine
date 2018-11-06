#ifndef _PHYSICS_MANAGER_H
#define _PHYSICS_MANAGER_H

// System Headers
#include <vector>

// My Headers
#include "CollisionManager.h"

class PhysicsManager
{
	CollisionManager collisionManager;

public:
	// Update
	void Update(float deltaTime, std::vector<class Agent*>* collidableObjects);
};

#endif