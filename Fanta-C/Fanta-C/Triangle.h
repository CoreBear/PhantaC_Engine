#ifndef _TRIANGLE_H
#define _TRIANGLE_H

// My Headers
#include "Mesh.h"

class Triangle : public Mesh
{
	constexpr static uchar	numberOfVertices = 3;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	// Private
	void CreateMesh();

public:
	// Initialization
	Triangle(float inScale = 1) : Mesh(true, inScale) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif