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
	void CreateMesh(float inWidth, float inHeight, float inDepth, float inScale);

public:
	// Initialization
	Pyramid(float inWidth, float inHeight, float inDepth, float inScale = 1) : Mesh(Colors::Blue, inWidth, inHeight, inDepth, inScale) { CreateMesh(inWidth, inHeight, inDepth, inScale); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer* lineRenderer) override;
};

#endif