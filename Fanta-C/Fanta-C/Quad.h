#ifndef _QUAD_H
#define _QUAD_H

// My Headers
#include "CollidableObject.h"
#include "GlobalGame.h"

class Quad : public CollidableObject
{
	constexpr static uchar	numberOfVertices = 4;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	void CreateShape(float scale);

public:
	// Initialization
	Quad(float scale = 1) : CollidableObject(worldOrigin, scale, true) { CreateShape(scale); }
	Quad(const XMVECTOR& position, float scale = 1) : CollidableObject(position, scale, true) { CreateShape(scale); }
	Quad(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float scale = 1) : CollidableObject(position, forward, up, scale, true) { CreateShape(scale); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif