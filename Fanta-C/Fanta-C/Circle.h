#ifndef _CIRCLE_H
#define _CIRCLE_H

// My Headers
#include "Shape.h"

class Circle : public Shape
{
	constexpr static ushort		numberOfVertices = 360;
	SIMPLE_VERTEX				vertices[numberOfVertices];

	void CreateMesh();

public:
	// Initialization
	Circle(const XMVECTOR& position = { 0, 0, 0, 1 }, float inScale = 1) : Shape(position, true, inScale) { CreateMesh(); }
	Circle(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : Shape(position, forward, up, true, inScale) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif