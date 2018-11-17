#ifndef _CIRCLE_H
#define _CIRCLE_H

// My Headers
#include "Mesh.h"

class Circle : public Mesh
{
	constexpr static ushort		numberOfVertices = 360;
	SIMPLE_VERTEX				vertices[numberOfVertices];

	void CreateMesh();

public:
	// Initialization
	Circle(float inScale = 1) : Mesh(true, inScale, Colors::Red) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif