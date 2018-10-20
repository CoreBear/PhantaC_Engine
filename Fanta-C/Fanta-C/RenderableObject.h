#ifndef _RENDERABLE_OBJECT_H
#define _RENDERABLE_OBJECT_H

// My Headers
#include "GlobalDirectX.h"
#include "LineRenderer.h"
#include "ObjectTransform.h"
#include "Typedefs.h"

class RenderableObject : public ObjectTransform
{
public:
	// Initialization
	RenderableObject(float inMoveSpeed, float inRotationSpeed) : ObjectTransform(inMoveSpeed, inRotationSpeed) { return; }
	RenderableObject(XMVECTOR* position, float inMoveSpeed, float inRotationSpeed) : ObjectTransform(position, inMoveSpeed, inRotationSpeed) { return; }
	RenderableObject(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float inMoveSpeed, float inRotationSpeed) : ObjectTransform(false, position, forward, up, inMoveSpeed, inRotationSpeed) { return; }

	// Public Interface
	virtual void AddMeToLineRenderer(LineRenderer& lineRenderer) = 0;
};

#endif
