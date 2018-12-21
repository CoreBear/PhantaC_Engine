#ifndef _BOUNDING_BOX_COLLISION_H
#define _BOUNDING_BOX_COLLISION_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalSceneVariables.h"
#include "MyArray.h"
#include "GlobalTypedefs.h"

// Forward Declarations
class SceneObject;

class BoundingBoxCollision
{
	// Variables
	float							extentLength;
	float							lengthToCorner;
	float							objectAxisPosition;
	class BoundingBox*				boxBeingChecked[2];
	static BoundingBoxCollision*	bbCollisionInstance;
	SceneObject*					objectsBeingChecked[2];
	ushort							collisionIterators[5];
	XMVECTOR						min[2];
	XMVECTOR						max[2];

	// Initialization
	BoundingBoxCollision() { return; }
	BoundingBoxCollision(BoundingBoxCollision const&) = delete;
	BoundingBoxCollision operator=(BoundingBoxCollision const&) = delete;

	// Private Functionality
	void AssignCollisionObjects(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* objectsInMyContainer);
	void CheckForCollision();

public:
	// Initialization
	static BoundingBoxCollision* GetInstance();

	// Update
	void Update(class PartitionGrid* grid);
};

#endif