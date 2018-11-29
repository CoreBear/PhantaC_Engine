#ifndef _BOUNDING_BOX_H
#define _BOUNDING_BOX_H

// System Headers
#include <vector>

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

// Forward Declarations
class ObjectManager;

class BoundingBox
{
	bool						isColliding;
	std::vector<ObjectManager*>	collidingObjects;
	uchar						boundingIterator;
	XMVECTOR					extents;						// Also the max

	void CreateBounds(float inWidth, float inHeight, float inDepth, float inScale);

public:
	// Initialization
	BoundingBox(float inWidth, float inHeight, float inDepth, float inScale) : isColliding(false) { CreateBounds(inWidth, inHeight, inDepth, inScale); }

	// Public Interface
	void AddCollidingObject(ObjectManager* collidingObject) { collidingObjects.push_back(collidingObject);}
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