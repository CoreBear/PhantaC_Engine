#ifndef _CUBE_H
#define _CUBE_H

// My Headers
#include "CollidableObject.h"
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"

class Cube : public CollidableObject
{
	constexpr static uchar	numberOfLinesTriIndicesVertices[3] = { 3, 4, 8 };
	uchar					triIndices[numberOfLinesTriIndicesVertices[1]][numberOfLinesTriIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLinesTriIndicesVertices[2]];

	// Private
	void CreateShape(float scale);

public:
	// Initialization
	Cube(float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(scale, inMoveSpeed, inRotationSpeed) { CreateShape(scale); }
	Cube(XMVECTOR* position, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, scale, inMoveSpeed, inRotationSpeed) { CreateShape(scale); }
	Cube(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : CollidableObject(position, forward, up, scale, inMoveSpeed, inRotationSpeed) { CreateShape(scale); }
	
	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif