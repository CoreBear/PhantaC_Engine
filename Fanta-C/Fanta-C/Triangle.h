#ifndef _TRIANGLE_H
#define _TRIANGLE_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderObject.h"

class Triangle : public RenderObject
{
	constexpr static uchar	numberOfVertices = 3;
	SIMPLE_VERTEX			vertices[numberOfVertices];

public:
	// Initialization
	Triangle(float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0);
	Triangle(XMVECTOR* position, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0);
	Triangle(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif