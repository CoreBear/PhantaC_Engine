#ifndef _COLLIDABLE_OBJECT_H
#define _COLLIDABLE_OBJECT_H

// My Headers
#include "GlobalDirectX.h"
#include "RenderableObject.h"

class CollidableObject : public RenderableObject
{
	XMVECTOR	centroid;
	XMVECTOR	extents;			// Also the max

	void CreateBounds(bool shapeIsFlat, float scale);

public:
	// Initialization
	CollidableObject(float scale, float inMoveSpeed, float inRotationSpeed, bool shapeIsFlat = false) : centroid(XMVectorSet(0, 0, 0, 1)), RenderableObject(&XMVectorSet(0, 0, 0, 1), inMoveSpeed, inRotationSpeed) { CreateBounds(shapeIsFlat, scale); }
	CollidableObject(XMVECTOR* position, float scale, float inMoveSpeed, float inRotationSpeed, bool shapeIsFlat = false) : RenderableObject(position, inMoveSpeed, inRotationSpeed) { CreateBounds(shapeIsFlat, scale); }
	CollidableObject(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale, float inMoveSpeed, float inRotationSpeed, bool shapeIsFlat = false) : RenderableObject(position, forward, up, inMoveSpeed, inRotationSpeed) { CreateBounds(shapeIsFlat, scale); }
};

#endif