#ifndef _PHYSICS_MANAGER_H
#define _PHYSICS_MANAGER_H

// System Headers
#include <vector>

// My Headers
#include "CollisionManager.h"

// Forward Declarations
class SceneObject;

class PhysicsManager
{
	class CollisionManager* collisionManager;

public:
	// Initialization
	PhysicsManager(SceneObject* grid) { collisionManager = new CollisionManager(grid); }

	// Update
	void Update(std::vector<SceneObject*>* collidableObjects);

	// Clean Up
	~PhysicsManager() { if (collisionManager) delete collisionManager; }
};

#endif