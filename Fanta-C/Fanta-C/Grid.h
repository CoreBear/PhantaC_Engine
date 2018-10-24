#ifndef _GRID_H
#define _GRID_H

// My Headers
#include "Shape.h"

class Grid : public Shape
{
	constexpr static ushort		numberOfVertices = 500;				// Make sure this number is a multiple of 4. Half the number of lines
	SIMPLE_VERTEX				vertices[numberOfVertices];			// First 22 are horizontal

	void CreateMesh();

public:
	// Initialization
	Grid(const XMVECTOR& position = { 0, 0, 0, 1 }, float inScale = 1) : Shape(position, true, inScale) { CreateMesh(); }
	Grid(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : Shape(position, forward, up, true, inScale) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif