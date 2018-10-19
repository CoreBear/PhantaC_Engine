#ifndef _QUAD_H
#define _QUAD_H

#include "GeometricObject.h"
#include "GeometryGlobals.h"
#include "LineRenderer.h"
#include "ProgramGlobals.h"

class Quad : public GeometricObject
{
	constexpr static uchar	numberOfVertices = 4;
	SIMPLE_VERTEX			vertices[numberOfVertices];

public:
	// Initialization
	Quad(float scale = 1);
	Quad(float x, float y, float z, float scale = 1);

	// Update
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override;

	// Accessors
	const uchar GetNumberOfVertices() const { return numberOfVertices; }
	const SIMPLE_VERTEX* GetVertices() const { return vertices; }
};

#endif