#ifndef _RENDER_OBJECT_H
#define _RENDER_OBJECT_H

// My Headers
#include "GlobalDirectX.h"
#include "LineRenderer.h"
#include "MoveableObject.h"
#include "Typedefs.h"

class RenderObject : public MoveableObject
{
public:
	// Initialization
	RenderObject(float inMoveSpeed, float inRotationSpeed) : MoveableObject(inMoveSpeed, inRotationSpeed) { return; }
	RenderObject(XMVECTOR* position, float inMoveSpeed, float inRotationSpeed) : MoveableObject(position, inMoveSpeed, inRotationSpeed) { return; }
	RenderObject(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float inMoveSpeed, float inRotationSpeed) : MoveableObject(false, position, forward, up, inMoveSpeed, inRotationSpeed) { return; }

	// Public Interface
	virtual void AddMeToLineRenderer(LineRenderer& lineRenderer) = 0;
};

#endif
