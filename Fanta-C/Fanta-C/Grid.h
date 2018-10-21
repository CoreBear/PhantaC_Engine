#ifndef _GRID_H
#define _GRID_H

// My Headers
#include "CollidableObject.h"
#include "GlobalGame.h"

class Grid : public CollidableObject
{
	constexpr static ushort				numberOfVertices = 500;				// Make sure this number is a multiple of 4. Half the number of lines
	SIMPLE_VERTEX						vertices[numberOfVertices];			// First 22 are horizontal

	void CreateShape();

public:
	// Initialization
	Grid() : CollidableObject(worldOrigin, 1, true) { CreateShape(); }
	Grid(const XMVECTOR& position) : CollidableObject(position, 1, true) { CreateShape(); }
	Grid(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up) : CollidableObject(position, forward, up, 1, true) { CreateShape(); }

	// Public Interface
	void AddMeToLineRenderer(class LineRenderer& lineRenderer) override;
};

#endif