#ifndef _CUBE_H
#define _CUBE_H

// My Headers
#include "CollidableObject.h"
#include "GlobalGame.h"

class Cube : public CollidableObject
{
	constexpr static uchar	numberOfLinesTriIndicesVertices[3] = { 3, 4, 8 };
	uchar					triIndices[numberOfLinesTriIndicesVertices[1]][numberOfLinesTriIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLinesTriIndicesVertices[2]];

	// Private
	void CreateShape(float scale);

public:
	// Initialization
	Cube(float scale = 1) : CollidableObject(worldOrigin, scale, true) { CreateShape(scale); }
	Cube(const XMVECTOR& position, float scale = 1) : CollidableObject(position, scale) { CreateShape(scale); }
	Cube(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float scale = 1) : CollidableObject(position, forward, up, scale) { CreateShape(scale); }
	
	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif