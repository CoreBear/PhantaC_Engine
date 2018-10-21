#ifndef _CIRCLE_H
#define _CIRCLE_H

// My Headers
#include "CollidableObject.h"
#include "GlobalGame.h"

class Circle : public CollidableObject
{
	constexpr static ushort		numberOfVertices = 360;
	SIMPLE_VERTEX				vertices[numberOfVertices];

	void CreateShape(float scale);

public:
	// Initialization
	Circle(float scale = 1) : CollidableObject(worldOrigin, scale, true) { CreateShape(scale); }
	Circle(const XMVECTOR& position, float scale = 1) : CollidableObject(position, scale, true) { CreateShape(scale); }
	Circle(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float scale = 1) : CollidableObject(position, forward, up, scale, true) { CreateShape(scale); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif