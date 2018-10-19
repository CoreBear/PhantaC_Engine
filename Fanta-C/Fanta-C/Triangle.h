#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "GeometricObject.h"
#include "GeometryGlobals.h"
#include "LineRenderer.h"
#include "ProgramGlobals.h"

class Triangle : public GeometricObject
{
	constexpr static uchar	numberOfVertices = 3;
	SIMPLE_VERTEX			vertices[numberOfVertices];

public:
	// Initialization
	Triangle(float scale = 1);
	Triangle(XMVECTOR* position, float scale = 1);
	Triangle(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Update
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override;
};

#endif