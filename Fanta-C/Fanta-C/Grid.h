#ifndef _GRID_H
#define _GRID_H

// My Headers
#include "Mesh.h"

class Grid : public Mesh
{
	constexpr static ushort		numberOfVertices = 500;				// Make sure this number is a multiple of 4. Half the number of lines
	SIMPLE_VERTEX				vertices[numberOfVertices];			// First 22 are horizontal

	void CreateMesh();

public:
	// Initialization
	Grid(float inScale = 1) : Mesh(true, inScale) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif