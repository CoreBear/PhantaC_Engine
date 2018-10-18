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
	GeometricObject(char x, char y, char z) : TransformObject(x, y, z) {};

	// Update
	virtual void AddMeToLineRenderer(LineRenderer& lineRenderer) {};		// Figure out how to make this a purely virtual function and make the class an ABC
};

#endif
