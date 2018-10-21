#ifndef _PYRAMID_H
#define _PYRAMID_H

// My Headers
#include "CollidableObject.h"
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"

class Pyramid : public CollidableObject
{
	constexpr static uchar	numberOfLineIndicesVertices[2] = { 8, 5 };
	uchar					lineIndices[numberOfLineIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLineIndicesVertices[1]];

	// Private
	void CreateShape(float scale);

public:
	// Initialization
	Pyramid(float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(scale, inMoveSpeed, inRotationSpeed) { CreateShape(scale); }
	Pyramid(XMVECTOR* position, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, scale, inMoveSpeed, inRotationSpeed) { CreateShape(scale); }
	Pyramid(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, forward, up, scale, inMoveSpeed, inRotationSpeed) { CreateShape(scale); }
	
	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif