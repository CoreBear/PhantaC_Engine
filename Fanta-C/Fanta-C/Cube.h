#ifndef _CUBE_H
#define _CUBE_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderableObject.h"

class Cube : public RenderableObject
{
	constexpr static uchar	numberOfLinesTriIndicesVertices[3] = { 3, 4, 8 };
	uchar					triIndices[numberOfLinesTriIndicesVertices[1]][numberOfLinesTriIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLinesTriIndicesVertices[2]];

	// Private
	void Create(float scale);

public:
	// Initialization
	Cube(float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(inMoveSpeed, inRotationSpeed) { Create(scale); }
	Cube(XMVECTOR* position, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(position, inMoveSpeed, inRotationSpeed) { Create(scale); }
	Cube(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0) : RenderableObject(position, forward, up, inMoveSpeed, inRotationSpeed) { Create(scale); }
	
	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif