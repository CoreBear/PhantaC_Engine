#ifndef _GRID_H
#define _GRID_H

// My Headers
#include "GlobalGame.h"
#include "GlobalGeometry.h"
#include "ObjectTransform.h"

class Grid : public ObjectTransform
{
	constexpr static ushort		numberOfVertices = 500;				// Make sure this number is a multiple of 4. Half the number of lines
	SIMPLE_VERTEX				vertices[numberOfVertices];			// First 22 are horizontal

	void CreateShape();

public:
	// Initialization
	Grid() : ObjectTransform(worldOrigin) { CreateShape(); }
	Grid(const XMVECTOR& position) : ObjectTransform(position) { CreateShape(); }
	Grid(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up) : ObjectTransform(false, position, forward, up) { CreateShape(); }

	// Public Interface
	void DrawMe(LineRenderer& lineRenderer) override;
};

#endif