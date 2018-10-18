#ifndef _CUBE_H
#define _CUBE_H

#include "GeometricObject.h"
#include "GeometryGlobals.h"
#include "LineRenderer.h"
#include "ProgramGlobals.h"

class Cube : public GeometricObject
{
	constexpr static uchar	numberOfIndicesVertices[2] = { 18, 8 };
	uchar					indices[numberOfIndicesVertices[0]];
	SIMPLE_VERTEX			vertices[numberOfIndicesVertices[1]];

public:
	// Initialization
	Cube();
	Cube(char x, char y, char z);

	// Update
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override;

	// Accessors
	const uchar* GetIndices() const { return indices; }
	const uchar GetNumberOfIndicesVertices(char index) const { return numberOfIndicesVertices[index]; }
	const SIMPLE_VERTEX* GetVertices() const { return vertices; }
};

#endif