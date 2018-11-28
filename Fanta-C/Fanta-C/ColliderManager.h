#ifndef _COLLIDER_MANAGER_H
#define _COLLIDER_MANAGER_H

// My Headers
#include "BoundingBox.h"
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

class ColliderManager
{
	BoundingBox* myBoundingBox;

public:
	// Initialization
	ColliderManager(bool inMeshIsFlat, float inScale) { myBoundingBox = new BoundingBox(inMeshIsFlat, inScale); }

	// Accessors
	BoundingBox* GetBoundingBox() { return myBoundingBox; }

	// Clean Up
	~ColliderManager() { if (myBoundingBox) delete myBoundingBox; }
};

#endif