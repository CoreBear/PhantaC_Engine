#ifndef _TRIANGLE_H
#define _TRIANGLE_H

// My Headers
#include "Shape.h"

class Triangle : public Shape
{
	constexpr static uchar	numberOfVertices = 3;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	// Private
	void CreateMesh();

public:
	// Initialization
	Triangle(const XMVECTOR& position = { 0, 0, 0, 1 }, float inScale = 1) : Shape(position, true, inScale) { CreateMesh(); }
	Triangle(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : Shape(position, forward, up, true, inScale) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif