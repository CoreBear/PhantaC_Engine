#ifndef _SHAPE_H
#define _SHAPE_H

// My Headers
#include "Mesh.h"

class Shape : public Mesh
{
public:
	// Initialization
	Shape(const XMVECTOR& position, bool isFlat, float inScale) : Mesh(position, isFlat, inScale) { return; }
	Shape(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, bool isFlat, float inScale) : Mesh(position, forward, up, isFlat, inScale) { return; }

	// Public Interface
	virtual void AddMyLinesToRenderer(LineRenderer& lineRenderer) = 0;
};

#endif
