#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "GeometricObject.h"
#include "GeometryGlobals.h"
#include "LineRenderer.h"
#include "ProgramGlobals.h"

class Triangle : public GeometricObject
{
	constexpr static uchar	numberOfVertices = 3;
	SIMPLE_VERTEX			vertices[numberOfVertices];

public:
	// Initialization
	Triangle(float scale = 1);
	Triangle(float x, float y, float z, float scale = 1);

	// Update
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override;

	// Accessors
	const uchar GetNumberOfVertices() const { return numberOfVertices; }
	const SIMPLE_VERTEX* GetVertices() const { return vertices; }
};

#endif