#ifndef _QUAD_H
#define _QUAD_H

// My Headers
#include "CollidableObject.h"
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"

class Quad : public CollidableObject
{
	constexpr static uchar	numberOfVertices = 4;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	void CreateShape(float scale);

public:
	// Initialization
	Quad(float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }
	Quad(XMVECTOR* position, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }
	Quad(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, forward, up, scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif