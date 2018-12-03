#ifndef _BOUNDING_BOX_COLLISION_H
#define _BOUNDING_BOX_COLLISION_H

// System Headers
#include <vector>


// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

class BoundingBoxCollision
{
	float					extentLength;
	float					lengthToCorner;
	float					objectAxisPosition;
	class BoundingBox*		boxBeingChecked[2];
	class ObjectManager*	objectsBeingChecked[2];
	ushort					collisionIterators[5];
	XMVECTOR				min[2];
	XMVECTOR				max[2];

public:
	// Update
	void CheckForCollision();
	void AssignCollisionObjects(std::vector<ObjectManager*>* collidableObjects);
	void Update(std::vector<class PartitionCell*>* gridCells);
};

#endif