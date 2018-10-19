#ifndef _PYRAMID_H
#define _PYRAMID_H

#include "GeometricObject.h"
#include "GeometryGlobals.h"
#include "LineRenderer.h"
#include "ProgramGlobals.h"

class Pyramid : public GeometricObject
{
	constexpr static uchar	numberOfIndicesVertices[2] = { 13, 5 };
	uchar					indices[numberOfIndicesVertices[0]];
	XMVECTOR				centroid;
	XMVECTOR				extents;									// Also the max
	SIMPLE_VERTEX			vertices[numberOfIndicesVertices[1]];

public:
	// Initialization
	Pyramid(float scale = 1);
	Pyramid(XMVECTOR* position, float scale = 1);
	Pyramid(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale = 1, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Public Interface
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override;

	// Accessors
	const uchar* GetIndices() const { return indices; }
	const uchar GetNumberOfIndicesVertices(char index) const { return numberOfIndicesVertices[index]; }
	const SIMPLE_VERTEX* GetVertices() const { return vertices; }
};

#endif