#ifndef _CIRCLE_H
#define _CIRCLE_H

// My Headers
#include "Mesh.h"

class Circle : public Mesh
{
	constexpr static ushort		numberOfVertices = 360;
	SIMPLE_VERTEX				vertices[numberOfVertices];

	// Private
	void CreateMesh(float inWidth, float inHeight, float inDepth, float inScale);

public:
	// Initialization
	Circle(float inWidth, float inHeight, float inDepth, float inScale = 1) : Mesh(inWidth, inHeight, inDepth, inScale, Colors::Red) { CreateMesh(inWidth, inHeight, inDepth, inScale); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif