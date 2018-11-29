#ifndef _TRIANGLE_H
#define _TRIANGLE_H

// My Headers
#include "Mesh.h"

class Triangle : public Mesh
{
	constexpr static uchar	numberOfVertices = 3;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	// Private
	void CreateMesh(float inWidth, float inHeight, float inDepth, float inScale);

public:
	// Initialization
	Triangle(float inWidth, float inHeight, float inDepth, float inScale = 1) : Mesh(inWidth, inHeight, inDepth, inScale, Colors::Yellow) { CreateMesh(inWidth, inHeight, inDepth, inScale); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif