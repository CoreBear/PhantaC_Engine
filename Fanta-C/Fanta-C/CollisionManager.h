#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

// System Headers
#include <vector>

// Forward Declarations
class SceneObject;

class CollisionManager
{
	class BoundingBoxCollision* boundingBoxCollisionPtr;
	class PartitioningManager*	partitioningManagerPtr;

public:
	// Initialization
	CollisionManager(SceneObject* grid);

	// Update
	void Update(std::vector<SceneObject*>* collidableObjects);

	// Clean Up
	~CollisionManager();
};

#endif