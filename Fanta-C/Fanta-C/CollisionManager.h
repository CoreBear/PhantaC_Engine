#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

// System Headers
#include <vector>

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
	void Update(std::vector<SceneObject*>* collidableObjects);

	// Accessors
	static CollisionManager* GetInstance(SceneObject* grid = nullptr);

	// Clean Up
	~CollisionManager();
};

#endif