#ifndef _QUAD_H
#define _QUAD_H

// My Headers
#include "Mesh.h"

class Quad : public Mesh
{
	constexpr static uchar	numberOfVertices = 4;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	// Private
	void CreateMesh(float inWidth, float inHeight, float inDepth, float inScale);

public:
	// Initialization
	Quad(float inWidth, float inHeight, float inDepth, float inScale = 1) : Mesh(inWidth, inHeight, inDepth, inScale, Colors::Orange) { CreateMesh(inWidth, inHeight, inDepth, inScale); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif