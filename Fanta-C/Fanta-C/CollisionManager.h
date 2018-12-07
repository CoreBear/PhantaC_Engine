#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"
#include "GlobalSceneVariables.h"
#include "MyArray.h"

// Forward Declarations
class SceneObject;

class CollisionManager
{
	class BoundingBoxCollision* boundingBoxCollisionPtr;
	static CollisionManager*	collisionManagerInstance;
	class PartitioningManager*	partitioningManagerPtr;

	// Initialization
	CollisionManager(SceneObject* grid);
	CollisionManager(CollisionManager const&) = delete;
	CollisionManager operator=(CollisionManager const&) = delete;

public:
	// Update
	void Update(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects);

	// Accessors
	static CollisionManager* GetInstance(SceneObject* grid = nullptr);

	// Clean Up
	~CollisionManager();
};

#endif