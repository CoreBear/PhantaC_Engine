#ifndef _PARTITION_GRID_H
#define _PARTITION_GRID_H

// System Header
#include <vector>

// My Headers
#include "GlobalTypedefs.h"

class PartitionGrid
{
	std::vector<class PartitionCell*> gridCells;

public:
	// Initialization	
	PartitionGrid(class ObjectManager* grid);

	// Accessors
	std::vector<PartitionCell*>* GetGridCells() { return &gridCells; }

	// Clean Up
	~PartitionGrid();
};

#endif