#ifndef _RENDERABLE_OBJECT_H
#define _RENDERABLE_OBJECT_H

// My Headers
#include "GlobalTypedefs.h"
#include "LineRenderer.h"
#include "ObjectTransform.h"

class RenderableObject : public ObjectTransform
{
public:
	// Initialization
	RenderableObject(const XMVECTOR& position) : ObjectTransform(position) { return; }
	RenderableObject(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up) : ObjectTransform(false, position, forward, up) { return; }

	// Public Interface
	virtual void AddMeToLineRenderer(LineRenderer& lineRenderer) = 0;
};

#endif
