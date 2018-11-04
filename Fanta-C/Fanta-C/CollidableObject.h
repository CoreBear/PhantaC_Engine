#ifndef _COLLIDABLE_OBJECT_H
#define _COLLIDABLE_OBJECT_H

#include "GlobalDirectX.h"

class CollidableObject
{
	bool		isColliding;
	XMVECTOR	extents;			// Also the max

	void CreateBounds(bool meshIsFlat, float scale);

public:
	// Initialization
	CollidableObject(bool inMeshIsFlat, float inScale) { CreateBounds(inMeshIsFlat, inScale); }

	// Accessors
	XMVECTOR GetExtents() const { return extents; }

	// Mutators
	void ToggleColliding() { isColliding = !isColliding; }
};

#endif