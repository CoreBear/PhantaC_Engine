#ifndef _TRIANGLE_H
#define _TRIANGLE_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderableObject.h"

class Triangle : public RenderableObject
{
	constexpr static uchar	numberOfVertices = 3;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	// Private
	void Create(float scale);

public:
	// Initialization
	Triangle(float scale = 0, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(inMoveSpeed, inRotationSpeed) { Create(scale); }
	Triangle(XMVECTOR* position, float scale = 0, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(position, inMoveSpeed, inRotationSpeed) { Create(scale); }
	Triangle(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 0, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(position, forward, up, inMoveSpeed, inRotationSpeed) { Create(scale); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif