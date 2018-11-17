#ifndef _QUAD_H
#define _QUAD_H

// My Headers
#include "Mesh.h"

class Quad : public Mesh
{
	constexpr static uchar	numberOfVertices = 4;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	void CreateMesh();

public:
	// Initialization
	Quad(float inScale = 1) : Mesh(true, inScale, Colors::Orange) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif