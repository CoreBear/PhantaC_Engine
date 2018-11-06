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
	Circle(const XMVECTOR& position = { 0, 0, 0, 1 }, float inScale = 1) : Mesh(position, true, inScale, Colors::Red) { CreateMesh(); }
	Circle(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : Mesh(position, forward, up, true, inScale, Colors::Red) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif