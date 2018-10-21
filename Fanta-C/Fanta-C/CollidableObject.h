#ifndef _COLLIDABLE_OBJECT_H
#define _COLLIDABLE_OBJECT_H

// My Headers
#include "RenderableObject.h"

class CollidableObject : public RenderableObject
{
	XMVECTOR	centroid;
	XMVECTOR	extents;			// Also the max

	void CreateBounds(bool shapeIsFlat, float scale);

public:
	// Initialization
	CollidableObject(const XMVECTOR& position, float scale, bool shapeIsFlat = false) : centroid(position), RenderableObject(position) { CreateBounds(shapeIsFlat, scale); }
	CollidableObject(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float scale, bool shapeIsFlat = false) : RenderableObject(position, forward, up) { CreateBounds(shapeIsFlat, scale); }
};

#endif