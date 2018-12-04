#ifndef _PARTITIONING_MANAGER_H
#define _PARTITIONING_MANAGER_H

// System Headers
#include <vector>

// Forward Declarations
class SceneObject;

class PartitioningManager
{
	class PartitionGrid*	partitionGridPtr;
	class Partitioner*		partitionerPtr;

public:
	// Initialization
	PartitioningManager(SceneObject* grid);

	// Update
	void Update(std::vector<SceneObject*>* collidableObjects);

	// Accessor
	PartitionGrid* GetPartitionGrid() { return partitionGridPtr; }

	// Clean Up
	~PartitioningManager();
};

#endif