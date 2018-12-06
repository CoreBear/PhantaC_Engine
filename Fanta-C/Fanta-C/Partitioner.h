#ifndef _PARTITIONER_H
#define _PARTITIONER_H

// System Headers
#include <vector>

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class SceneObject;

class Partitioner
{
	static Partitioner*	partitionerInstance;
	ushort				iterators[2];

	Partitioner() { return; }
	Partitioner(Partitioner const&) = delete;
	Partitioner operator=(Partitioner const&) = delete;

public:
	// Update
	void Update(std::vector<SceneObject*>* collidableObject, std::vector<class PartitionCell*>* gridCells);

	// Accessors
	static Partitioner* GetInstance();
};

#endif