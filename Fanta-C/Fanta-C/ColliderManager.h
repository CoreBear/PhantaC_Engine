#ifndef _COLLIDER_MANAGER_H
#define _COLLIDER_MANAGER_H

// My Headers
#include "BoundingBox.h"
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

class ColliderManager
{
	BoundingBox* myBoundingBox = nullptr;

public:
	// Initialization
	ColliderManager(float inWidth, float inHeight, float inDepth, float inScale) : myBoundingBox(new BoundingBox(inWidth, inHeight, inDepth, inScale)) { return; }

	// Accessors
	BoundingBox* GetBoundingBox() { return myBoundingBox; }

	// Clean Up
	~ColliderManager()
	{
		if (myBoundingBox)
		{
			delete myBoundingBox;
			myBoundingBox = nullptr;
		}
	}
};

#endif