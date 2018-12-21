#ifndef _CUBE_H
#define _CUBE_H

// My Headers
#include "Mesh.h"

class Cube : public Mesh
{
	constexpr static ushort	numberOfLinesTriIndicesVertices[3] = { 3, 4, 8 };
	uchar					secondIterator;
	uchar					triIndices[numberOfLinesTriIndicesVertices[1]][numberOfLinesTriIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLinesTriIndicesVertices[2]];

	// Private
	void CreateMesh(float inWidth, float inHeight, float inDepth, float inScale);

public:
	// Initialization
	Cube(float inWidth, float inHeight, float inDepth, float inScale = 1) : Mesh(Colors::Green, inWidth, inHeight, inDepth, inScale) { CreateMesh(inWidth, inHeight, inDepth, inScale); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer* lineRenderer) override;
};

#endif