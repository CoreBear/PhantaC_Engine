#ifndef _QUAD_H
#define _QUAD_H

#include "GeometricObject.h"
#include "GeometryGlobals.h"
#include "LineRenderer.h"
#include "ProgramGlobals.h"

class Quad : public GeometricObject
{
	constexpr static uchar	numberOfVertices = 4;
	XMVECTOR				centroid;
	XMVECTOR				extents;							// Also the max
	SIMPLE_VERTEX			vertices[numberOfVertices];

public:
	// Initialization
	Quad(float scale = 1);
	Quad(XMVECTOR* position, float scale = 1);
	Quad(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Public Interface
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override;
};

#endif