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
	float				extentLength;
	float				lengthToCorner;
	float				objectAxisPosition;
	class BoundingBox*	boxBeingChecked[2];
	SceneObject*		objectsBeingChecked[2];
	ushort				collisionIterators[5];
	XMVECTOR			min[2];
	XMVECTOR			max[2];

public:
	// Update
	void CheckForCollision();
	void AssignCollisionObjects(std::vector<SceneObject*>* collidableObjects);
	void Update(std::vector<class PartitionCell*>* gridCells);
};

#endif