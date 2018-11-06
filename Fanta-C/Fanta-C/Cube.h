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
	Cube(const XMVECTOR& position = { 0, 0, 0, 1 }, float inScale = 1) : Mesh(position, false, inScale, Colors::Orange) { CreateMesh(); }
	Cube(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : Mesh(position, forward, up, false, inScale, Colors::Orange) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif