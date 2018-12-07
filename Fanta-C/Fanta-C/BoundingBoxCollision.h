#ifndef _BOUNDING_BOX_COLLISION_H
#define _BOUNDING_BOX_COLLISION_H

// My Headers
#include "EventManager.h"
#include "GlobalDirectX.h"
#include "GlobalSceneVariables.h"
#include "GlobalTypedefs.h"
#include "MyArray.h"

// Forward Declarations
class SceneObject;

class BoundingBoxCollision
{
	float							extentLength;
	float							lengthToCorner;
	float							objectAxisPosition;
	class BoundingBox*				boxBeingChecked[2];
	static BoundingBoxCollision*	bbCollisionInstance;
	EventManager*					eventManagerPtr;
	SceneObject*					objectsBeingChecked[2];
	ushort							collisionIterators[5];
	XMVECTOR						min[2];
	XMVECTOR						max[2];

	BoundingBoxCollision() { eventManagerPtr = EventManager::GetInstance(); }
	BoundingBoxCollision(BoundingBoxCollision const&) = delete;
	BoundingBoxCollision operator=(BoundingBoxCollision const&) = delete;

	// Private Functions
	void AssignCollisionObjects(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects);
	void CheckForCollision();

public:
	// Update
	void Update(class PartitionGrid* grid);

	// Accessors
	static BoundingBoxCollision* GetInstance();
};

#endif