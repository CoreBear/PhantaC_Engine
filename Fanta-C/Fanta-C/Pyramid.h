#ifndef _PYRAMID_H
#define _PYRAMID_H

// My Headers
#include "Mesh.h"

class Pyramid : public Mesh
{
	constexpr static uchar	numberOfLineIndicesVertices[2] = { 8, 5 };
	uchar					lineIndices[numberOfLineIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLineIndicesVertices[1]];

	// Private
	void CreateMesh();

public:
	// Initialization
	Pyramid(float inScale = 1) : Mesh(false, inScale) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif