#ifndef _TRIANGLE_H
#define _TRIANGLE_H

// My Headers
#include "CollidableObject.h"
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"

class Triangle : public CollidableObject
{
	constexpr static uchar	numberOfVertices = 3;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	// Private
	void CreateShape(float scale);

public:
	// Initialization
	Triangle(float scale = 0, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }
	Triangle(XMVECTOR* position, float scale = 0, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }
	Triangle(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 0, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, forward, up, scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif