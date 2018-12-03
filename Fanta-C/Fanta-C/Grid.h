#ifndef _GRID_H
#define _GRID_H

// My Headers
#include "Mesh.h"

class Grid : public Mesh
{
	float						edgeOfGridDistance;					
	constexpr static ushort		numberOfVertices = 500;				// Make sure this number is a multiple of 4. Half the number of lines
	SIMPLE_VERTEX				vertices[numberOfVertices];			// First 22 are horizontal

	// Private
	void CreateMesh();

public:
	// Initialization
	Grid() : Mesh(1, 1, 1, 1, Colors::White) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;

	// Accessors
	float GetEdgeOfGridDistance() { return edgeOfGridDistance; }
};

#endif