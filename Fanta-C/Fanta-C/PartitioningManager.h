#ifndef _PARTITIONING_MANAGER_H
#define _PARTITIONING_MANAGER_H

// My Headers
#include "GlobalSceneVariables.h"
#include "MyArray.h"

// Forward Declarations
class SceneObject;

class PartitioningManager
{
	class Partitioner*			partitionerPtr;
	class PartitionGrid*		partitionGridPtr;
	static PartitioningManager* partitioningManagerInstance;

	// Initialization
	PartitioningManager(SceneObject* grid);
	PartitioningManager(PartitioningManager const&) = delete;
	PartitioningManager operator=(PartitioningManager const&) = delete;

public:
	// Update
	void Update(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects);

	// Accessors
	PartitionGrid* GetPartitionGrid() { return partitionGridPtr; }
	static PartitioningManager* GetInstance(SceneObject* grid);

	// Clean Up
	~PartitioningManager();
};

#endif