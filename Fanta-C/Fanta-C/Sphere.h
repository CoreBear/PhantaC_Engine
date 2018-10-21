#ifndef _SPHERE_H
#define _SPHERE_H

// My Headers
#include "CollidableObject.h"
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"

class Sphere : public CollidableObject
{
	constexpr static ushort		numberOfVertices = 720;
	SIMPLE_VERTEX				vertices[numberOfVertices];

	void CreateShape(float scale);

public:
	// Initialization
	Sphere(float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }
	Sphere(XMVECTOR* position, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }
	Sphere(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, forward, up, scale, inMoveSpeed, inRotationSpeed, true) { CreateShape(scale); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif