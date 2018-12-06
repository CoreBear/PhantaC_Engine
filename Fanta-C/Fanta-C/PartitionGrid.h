#ifndef _PARTITION_GRID_H
#define _PARTITION_GRID_H

// System Header
#include <vector>

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class SceneObject;

class PartitionGrid
{
	static PartitionGrid*				partitionGridInstance;
	std::vector<class PartitionCell*>	gridCells;

	// Initialization	
	PartitionGrid(SceneObject* grid);
	PartitionGrid(PartitionGrid const&) = delete;
	PartitionGrid operator=(PartitionGrid const&) = delete;

public:
	// Accessors
	static PartitionGrid* GetInstance(SceneObject* grid);
	std::vector<PartitionCell*>* GetGridCells() { return &gridCells; }

	// Clean Up
	~PartitionGrid();
};

#endif