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
	Triangle(const XMVECTOR& position = { 0, 0, 0, 1 }, float inScale = 1) : Mesh(position, true, inScale, Colors::Brown) { CreateMesh(); }
	Triangle(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : Mesh(position, forward, up, true, inScale, Colors::Brown) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif