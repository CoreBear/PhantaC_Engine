#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class SceneObject;

class CollisionManager
{
	// Variables
	class BoundingBoxCollision* boundingBoxCollisionPtr;
	static CollisionManager*	collisionManagerInstance;
	class PartitioningManager*	partitioningManagerPtr;

	// Initialization
	CollisionManager(SceneObject* grid);
	CollisionManager(CollisionManager const&) = delete;
	CollisionManager operator=(CollisionManager const&) = delete;

public:
	// Initialization
	static CollisionManager* GetInstance(SceneObject* grid);

	// Update
	void Update();

	// Clean Up
	~CollisionManager();
};

#endif