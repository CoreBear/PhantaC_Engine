#ifndef _PYRAMID_H
#define _PYRAMID_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderableObject.h"

class Pyramid : public RenderableObject
{
	constexpr static uchar	numberOfLineIndicesVertices[2] = { 8, 5 };
	uchar					lineIndices[numberOfLineIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLineIndicesVertices[1]];

	// Private
	void Create(float scale);

public:
	// Initialization
	Pyramid(float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(inMoveSpeed, inRotationSpeed) { Create(scale); }
	Pyramid(XMVECTOR* position, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(position, inMoveSpeed, inRotationSpeed) { Create(scale); }
	Pyramid(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(position, forward, up, inMoveSpeed, inRotationSpeed) { Create(scale); }
	
	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif