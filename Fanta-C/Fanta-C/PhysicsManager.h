#ifndef _PHYSICS_MANAGER_H
#define _PHYSICS_MANAGER_H

// My Headers
#include "CollisionManager.h"
#include "GlobalTypedefs.h"
#include "GlobalSceneVariables.h"
#include "MyArray.h"

// Forward Declarations
class SceneObject;

class PhysicsManager
{
	// Variables
	class CollisionManager* collisionManager;
	static PhysicsManager*	physicsManagerInstance;

	// Initialization
	PhysicsManager(SceneObject* grid) { collisionManager = CollisionManager::GetInstance(grid); }
	PhysicsManager(PhysicsManager const&) = delete;
	PhysicsManager operator=(PhysicsManager const&) = delete;

public:
	// Initialization
	static PhysicsManager* GetInstance(SceneObject* grid = nullptr);

	// Update
	void Update();

	// Clean Up
	~PhysicsManager() { if (collisionManager) delete collisionManager; }
};

#endif