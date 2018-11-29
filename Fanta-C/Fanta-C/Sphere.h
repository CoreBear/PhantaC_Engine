#ifndef _SPHERE_H
#define _SPHERE_H

// My Headers
#include "Mesh.h"

class Sphere : public Mesh
{
	constexpr static ushort		numberOfVertices = 720;
	SIMPLE_VERTEX				vertices[numberOfVertices];

	// Private
	void CreateMesh(float inWidth, float inHeight, float inDepth, float inScale);

public:
	// Initialization
	Sphere(float inWidth, float inHeight, float inDepth, float inScale = 1) : Mesh(inWidth, inHeight, inDepth, inScale, Colors::Purple) { CreateMesh(inWidth, inHeight, inDepth, inScale); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif