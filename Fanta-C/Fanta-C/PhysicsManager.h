#ifndef _PHYSICS_MANAGER_H
#define _PHYSICS_MANAGER_H

// System Headers
#include <vector>

// My Headers
#include "CollisionManager.h"

class PhysicsManager
{
	class CollisionManager* collisionManager;

public:
	// Initialization
	PhysicsManager(class ObjectManager* grid) { collisionManager = new CollisionManager(grid); }

	// Update
	void Update(std::vector<ObjectManager*>* collidableObjects);

	// Clean Up
	~PhysicsManager() { if (collisionManager) delete collisionManager; }
};

#endif