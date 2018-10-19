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
	SIMPLE_VERTEX			vertices[numberOfIndicesVertices[1]];

public:
	// Initialization
	Pyramid(float scale = 1);
	Pyramid(float x, float y, float z, float scale = 1);

	// Update
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override;

	// Accessors
	const uchar* GetIndices() const { return indices; }
	const uchar GetNumberOfIndicesVertices(char index) const { return numberOfIndicesVertices[index]; }
	const SIMPLE_VERTEX* GetVertices() const { return vertices; }
};

#endif