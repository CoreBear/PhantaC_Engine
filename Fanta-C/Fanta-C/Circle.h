#ifndef _CIRCLE_H
#define _CIRCLE_H

// My Headers
#include "CollidableObject.h"
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"

class Circle : public CollidableObject
{
	constexpr static ushort		numberOfVertices = 360;
	SIMPLE_VERTEX				vertices[numberOfVertices];

	void CreateShape(float scale);

public:
	// Initialization
	Circle(float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }
	Circle(XMVECTOR* position, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }
	Circle(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, forward, up, scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif