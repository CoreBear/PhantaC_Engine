#ifndef _GEOMETRIC_OBJECT_H
#define _GEOMETRIC_OBJECT_H

#include "Typedefs.h"
#include "TransformObject.h"
#include "LineRenderer.h"

class GeometricObject : public TransformObject
{
public:
	// Initialization
	GeometricObject() { return; }
	GeometricObject(float inMoveSpeed) : TransformObject(inMoveSpeed) { return; }
	GeometricObject(XMVECTOR* position) : TransformObject(position) { return; }
	GeometricObject(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float inMoveSpeed = 0, float inRotationSpeed = 0) : TransformObject(false, *position, *forward, *up, inMoveSpeed, inRotationSpeed) { return; }

	// Update
	void Update() override { return; }

	// Public Interface
	virtual void AddMeToLineRenderer(LineRenderer& lineRenderer) { return; }	// Figure out how to make this a purely virtual function and make the class an ABC
};

#endif
