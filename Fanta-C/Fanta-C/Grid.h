#ifndef _GRID_H
#define _GRID_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderableObject.h"

class Grid : public RenderableObject
{
	constexpr static ushort				numberOfVertices = 500;
	SIMPLE_VERTEX						vertices[numberOfVertices];			// First 22 are horizontal

	void Create();

public:
	// Initialization
	Grid() : RenderableObject(0, 0) { Create(); }
	Grid(XMVECTOR* position) : RenderableObject(position, 0, 0) { Create(); }
	Grid(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up) : RenderableObject(position, forward, up, 0, 0) { Create(); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif