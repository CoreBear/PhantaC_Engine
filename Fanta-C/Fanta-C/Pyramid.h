#ifndef _PYRAMID_H
#define _PYRAMID_H

// My Headers
#include "CollidableObject.h"
#include "GlobalGame.h"

class Pyramid : public CollidableObject
{
	constexpr static uchar	numberOfLineIndicesVertices[2] = { 8, 5 };
	uchar					lineIndices[numberOfLineIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLineIndicesVertices[1]];

	// Private
	void CreateShape(float scale);

public:
	// Initialization
	Pyramid(float scale = 1) : CollidableObject(worldOrigin, scale, true) { CreateShape(scale); }
	Pyramid(const XMVECTOR& position, float scale = 1) : CollidableObject(position, scale) { CreateShape(scale); }
	Pyramid(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float scale = 1) : CollidableObject(position, forward, up, scale) { CreateShape(scale); }
	
	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif