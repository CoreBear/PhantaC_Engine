#ifndef _TRIANGLE_H
#define _TRIANGLE_H

// My Headers
#include "CollidableObject.h"
#include "GlobalGame.h"

class Triangle : public CollidableObject
{
	constexpr static uchar	numberOfVertices = 3;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	// Private
	void CreateShape(float scale);

public:
	// Initialization
	Triangle(float scale = 1) : CollidableObject(worldOrigin, scale, true) { CreateShape(scale); }
	Triangle(const XMVECTOR& position, float scale = 1) : CollidableObject(position, scale, true) { CreateShape(scale); }
	Triangle(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float scale = 1) : CollidableObject(position, forward, up, scale, true) { CreateShape(scale); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif