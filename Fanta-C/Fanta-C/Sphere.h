#ifndef _SPHERE_H
#define _SPHERE_H

// My Headers
#include "CollidableObject.h"
#include "GlobalGame.h"

class Sphere : public CollidableObject
{
	constexpr static ushort		numberOfVertices = 720;
	SIMPLE_VERTEX				vertices[numberOfVertices];

	void CreateShape(float scale);

public:
	// Initialization
	Sphere(float scale = 1) : CollidableObject(worldOrigin, scale, true) { CreateShape(scale); }
	Sphere(const XMVECTOR& position, float scale = 1) : CollidableObject(position, scale, true) { CreateShape(scale); }
	Sphere(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float scale = 1) : CollidableObject(position, forward, up, scale, true) { CreateShape(scale); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif