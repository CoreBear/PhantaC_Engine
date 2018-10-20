#ifndef _CUBE_H
#define _CUBE_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderObject.h"

class Cube : public RenderObject
{
	constexpr static uchar	numberOfIndicesVertices[2] = { 32, 8 };
	uchar					indices[numberOfIndicesVertices[0]];
	SIMPLE_VERTEX			vertices[numberOfIndicesVertices[1]];

public:
	// Initialization
	Cube(float scale = 1);
	Cube(XMVECTOR* position, float scale = 1);
	Cube(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1);

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif