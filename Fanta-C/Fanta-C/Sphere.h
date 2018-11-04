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
	Sphere(const XMVECTOR& position = { 0, 0, 0, 1 }, float inScale = 1) : Mesh(position, false, inScale) { CreateMesh(); }
	Sphere(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : Mesh(position, forward, up, false, inScale) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif