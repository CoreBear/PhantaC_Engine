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
	static PhysicsManager*	physicsManagerInstance;

	// Initialization
	PhysicsManager(SceneObject* grid) { collisionManager = CollisionManager::GetInstance(grid); }
	PhysicsManager(PhysicsManager const&) = delete;
	PhysicsManager operator=(PhysicsManager const&) = delete;

public:
	// Update
	void Update(std::vector<SceneObject*>* collidableObjects);

	// Accessors
	static PhysicsManager* GetInstance(SceneObject* grid = nullptr);

	// Clean Up
	~PhysicsManager() { if (collisionManager) delete collisionManager; }
};

#endif