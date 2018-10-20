#ifndef _RENDER_OBJECT_H
#define _RENDER_OBJECT_H

// My Headers
#include "GlobalDirectX.h"
#include "LineRenderer.h"
#include "TransformObject.h"
#include "Typedefs.h"

class RenderObject : public TransformObject
{
protected:
	XMVECTOR	centroid;
	XMVECTOR	extents;			// Also the max

public:
	// Initialization
	RenderObject() { centroid = XMVectorSet(0, 0, 0, 1); }
	RenderObject(XMVECTOR* position) : TransformObject(position) { return; }
	RenderObject(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up) : TransformObject(false, *position, *forward, *up) { return; }

	// Update
	//void Update() override { return; }

	// Public Interface
	virtual void AddMeToLineRenderer(LineRenderer& lineRenderer) { return; }	// Figure out how to make this a purely virtual function and make the class an ABC
};

#endif
