#ifndef _PARTITIONING_MANAGER_H
#define _PARTITIONING_MANAGER_H

// System Headers
#include <vector>

// Forward Declarations
class ObjectManager;

class PartitioningManager
{
	class PartitionGrid*	partitionGridPtr;
	class Partitioner*		partitionerPtr;

public:
	// Initialization
	PartitioningManager(ObjectManager* grid);

	// Update
	void Update(std::vector<ObjectManager*>* collidableObjects);

	// Accessor
	PartitionGrid* GetPartitionGrid() { return partitionGridPtr; }

	// Clean Up
	~PartitioningManager();
};

#endif