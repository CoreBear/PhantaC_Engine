#ifndef _PARTITION_GRID_H
#define _PARTITION_GRID_H

// My Headers
#include "GlobalTypedefs.h"
#include "PartitionCell.h"

// Forward Declarations
class SceneObject;

class PartitionGrid
{
	static PartitionGrid*				partitionGridInstance;
	class PartitionCell*				gridCells;
	uchar								numberOfTotalCells;

	// Initialization	
	PartitionGrid(SceneObject* grid);
	PartitionGrid(PartitionGrid const&) = delete;
	PartitionGrid operator=(PartitionGrid const&) = delete;

public:
	// Accessors
	static PartitionGrid* GetInstance(SceneObject* grid);
	PartitionCell* GetGridCells() { return gridCells; }
	uchar GetNumberOfTotalCells() { return numberOfTotalCells; }

	// Clean Up
	~PartitionGrid() { delete[] gridCells; }
};

#endif