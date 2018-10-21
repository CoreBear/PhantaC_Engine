#ifndef _GRID_H
#define _GRID_H

// My Headers
#include "CollidableObject.h"
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"

class Grid : public CollidableObject
{
	constexpr static ushort				numberOfVertices = 500;				// Make sure this number is a multiple of 4. Half the number of lines
	SIMPLE_VERTEX						vertices[numberOfVertices];			// First 22 are horizontal

	void CreateShape();

public:
	// Initialization
	Grid() : CollidableObject(1, 0, 0, true) { CreateShape(); }
	Grid(XMVECTOR* position) : CollidableObject(position, 1, 0, 0, true) { CreateShape(); }
	Grid(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up) : CollidableObject(position, forward, up, 1, 0, 0, true) { CreateShape(); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif