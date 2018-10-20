#ifndef _PYRAMID_H
#define _PYRAMID_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderObject.h"

class Pyramid : public RenderObject
{
	constexpr static uchar	numberOfIndicesVertices[2] = { 10, 5 };
	uchar					indices[numberOfIndicesVertices[0]];
	SIMPLE_VERTEX			vertices[numberOfIndicesVertices[1]];

public:
	// Initialization
	Pyramid(float scale = 1);
	Pyramid(XMVECTOR* position, float scale = 1);
	Pyramid(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1);

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif