#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

// System Headers
#include <vector>

// Forward Declarations
class ObjectManager;

class CollisionManager
{
	class BoundingBoxCollision* boundingBoxCollisionPtr;
	class PartitioningManager*	partitioningManagerPtr;

public:
	// Initialization
	CollisionManager(ObjectManager* grid);

	// Update
	void Update(std::vector<ObjectManager*>* collidableObjects);

	// Clean Up
	~CollisionManager();
};

#endif