#ifndef _BOUNDING_BOX_COLLISION_H
#define _BOUNDING_BOX_COLLISION_H

// System Headers
#include <vector>

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

// Forward Declarations
class SceneObject;

class BoundingBoxCollision
{
	float							extentLength;
	float							lengthToCorner;
	float							objectAxisPosition;
	class BoundingBox*				boxBeingChecked[2];
	static BoundingBoxCollision*	bbCollisionInstance;
	SceneObject*					objectsBeingChecked[2];
	ushort							collisionIterators[5];
	XMVECTOR						min[2];
	XMVECTOR						max[2];

	BoundingBoxCollision() { return; }
	BoundingBoxCollision(BoundingBoxCollision const&) = delete;
	BoundingBoxCollision operator=(BoundingBoxCollision const&) = delete;

	// Private Functions
	void AssignCollisionObjects(std::vector<SceneObject*>* collidableObjects);
	void CheckForCollision();

public:
	// Update
	void Update(std::vector<class PartitionCell*>* gridCells);

	// Accessors
	static BoundingBoxCollision* GetInstance();
};

#endif