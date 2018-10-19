#ifndef _GEOMETRIC_OBJECT_H
#define _GEOMETRIC_OBJECT_H

#include "Typedefs.h"
#include "TransformObject.h"
#include "LineRenderer.h"

class GeometricObject : public TransformObject
{
public:
	// Initialization
	GeometricObject() {};
	GeometricObject(XMVECTOR* position) : TransformObject(position) {};
	GeometricObject(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float inMoveSpeed = 0, float inRotationSpeed = 0) : TransformObject(false, *position, *forward, *up, inMoveSpeed, inRotationSpeed) {}

	// Update
	virtual void AddMeToLineRenderer(LineRenderer& lineRenderer) {};		// Figure out how to make this a purely virtual function and make the class an ABC
};

#endif
