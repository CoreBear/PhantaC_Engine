#ifndef _CUBE_H
#define _CUBE_H

// My Headers
#include "Mesh.h"

class Cube : public Mesh
{
	constexpr static uchar	numberOfLinesTriIndicesVertices[3] = { 3, 4, 8 };
	uchar					triIndices[numberOfLinesTriIndicesVertices[1]][numberOfLinesTriIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLinesTriIndicesVertices[2]];

	// Private
	void CreateMesh();

public:
	// Initialization
	Cube(float inScale = 1) : Mesh(false, inScale, Colors::Green) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif