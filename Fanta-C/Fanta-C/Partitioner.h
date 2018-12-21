#ifndef _PARTITIONER_H
#define _PARTITIONER_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class PartitionGrid;
class SceneObject;

class Partitioner
{
	// Variables
	PartitionGrid*															grid;
	static Partitioner*														partitionerInstance;
	ushort																	iterators[2];

	// Initialization
	Partitioner(PartitionGrid* inGrid) : grid(inGrid) { return; }
	Partitioner(Partitioner const&) = delete;
	Partitioner operator=(Partitioner const&) = delete;

public:
	// Initialization
	static Partitioner* GetInstance(PartitionGrid* inGrid);

	// Update
	void Update();
};

#endif