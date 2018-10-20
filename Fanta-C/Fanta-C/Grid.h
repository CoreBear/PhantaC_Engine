#ifndef _GRID_H
#define _GRID_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderObject.h"

class Grid : public RenderObject
{
	constexpr static ushort				numberOfVertices = 500;
	SIMPLE_VERTEX						vertices[numberOfVertices];			// First 22 are horizontal

public:
	// Initialization
	Grid();
	Grid(XMVECTOR* position);
	Grid(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up);
	
	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif