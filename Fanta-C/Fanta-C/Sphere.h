#ifndef _SPHERE_H
#define _SPHERE_H

// My Headers
#include "Mesh.h"

class Sphere : public Mesh
{
	constexpr static ushort		numberOfVertices = 720;
	SIMPLE_VERTEX				vertices[numberOfVertices];

	void CreateMesh();

public:
	// Initialization
	Sphere(float inScale = 1) : Mesh(false, inScale) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif