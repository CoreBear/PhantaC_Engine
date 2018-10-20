#ifndef _QUAD_H
#define _QUAD_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderableObject.h"

class Quad : public RenderableObject
{
	constexpr static uchar	numberOfVertices = 4;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	void Create(float scale);

public:
	// Initialization
	Quad(float scale = 0, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(inMoveSpeed, inRotationSpeed) { Create(scale); }
	Quad(XMVECTOR* position, float scale = 0, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(position, inMoveSpeed, inRotationSpeed) { Create(scale); }
	Quad(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 0, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(position, forward, up, inMoveSpeed, inRotationSpeed) { Create(scale); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif