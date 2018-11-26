#ifndef _COLLIDABLE_OBJECT_H
#define _COLLIDABLE_OBJECT_H

// System Headers
#include <vector>

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

// Forward Declaration
class ObjectManager;

class Collider
{
	bool						isColliding;
	std::vector<ObjectManager*>	collidingObjects;
	uchar						colliderIterator;
	XMVECTOR					extents;						// Also the max

	void CreateBounds(bool meshIsFlat, float scale);

public:
	// Initialization
	Collider(bool inMeshIsFlat, float inScale) : isColliding(false) { CreateBounds(inMeshIsFlat, inScale); }

	// Public Interface
	void AddCollidingObject(ObjectManager* collidingObject) { collidingObjects.push_back(collidingObject); }
	bool CheckIfObjectInContainer(ObjectManager* collidingObject);
	bool ContainerEmpty() { return (collidingObjects.size() > 0) ? false : true; }
	void RemoveCollidingObject(ObjectManager* removeObject);

	// Accessors
	bool GetColliding() { return isColliding; }
	XMVECTOR& GetExtents() { return extents; }
	
	// Mutators
	void SetExtents(float x, float y, float z);
	void ToggleColliding() { isColliding = !isColliding; }
};

#endif