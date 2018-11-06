#ifndef _COLLIDABLE_OBJECT_H
#define _COLLIDABLE_OBJECT_H

#include "GlobalDirectX.h"

class Collider
{
	bool		isColliding;
	XMVECTOR	extents;			// Also the max

	void CreateBounds(bool meshIsFlat, float scale);

public:
	// Initialization
	Collider(bool inMeshIsFlat, float inScale) : isColliding(false) { CreateBounds(inMeshIsFlat, inScale); }

	// Accessors
	bool GetColliding() { return isColliding; }
	XMVECTOR& GetExtents() { return extents; }
	
	// Mutators
	void ToggleColliding() { isColliding = !isColliding; }
};

#endif