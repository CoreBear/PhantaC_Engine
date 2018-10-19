#ifndef _GRID_H
#define _GRID_H

#include "GeometricObject.h"
#include "GeometryGlobals.h"
#include "ProgramGlobals.h"
#include "LineRenderer.h"
#include <DirectXMath.h>
using namespace DirectX;

class Grid : public GeometricObject
{
	constexpr static ushort				numberOfVertices = 500;
	SIMPLE_VERTEX						vertices[numberOfVertices];			// First 22 are horizontal

public:
	// Initialization
	Grid();
	Grid(XMVECTOR* position);
	
	// Update
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override;

	// Accessors
	const ushort GetNumberOfVertices() const { return numberOfVertices; }
	const SIMPLE_VERTEX* GetVertices() const { return vertices; }
};

#endif