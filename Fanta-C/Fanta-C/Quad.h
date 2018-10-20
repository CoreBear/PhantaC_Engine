#ifndef _QUAD_H
#define _QUAD_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderObject.h"

class Quad : public RenderObject
{
	constexpr static uchar	numberOfVertices = 4;
	SIMPLE_VERTEX			vertices[numberOfVertices];

public:
	// Initialization
	Quad(float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0);
	Quad(XMVECTOR* position, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0);
	Quad(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif