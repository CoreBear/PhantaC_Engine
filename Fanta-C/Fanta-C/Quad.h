#ifndef _QUAD_H
#define _QUAD_H

// My Headers
#include "Shape.h"

class Quad : public Shape
{
	constexpr static uchar	numberOfVertices = 4;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	void CreateMesh();

public:
	// Initialization
	Quad(const XMVECTOR& position = { 0, 0, 0, 1 }, float inScale = 1) : Shape(position, true, inScale) { CreateMesh(); }
	Quad(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : Shape(position, forward, up, true, inScale) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif