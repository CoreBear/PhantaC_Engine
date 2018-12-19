#ifndef _PARTITIONING_MANAGER_H
#define _PARTITIONING_MANAGER_H

// My Headers
#include "GlobalSceneVariables.h"
#include "MyArray.h"

// Forward Declarations
class SceneObject;

class PartitioningManager
{
	// Variables
	class Partitioner*			partitionerPtr;
	class PartitionGrid*		partitionGridPtr;
	static PartitioningManager* partitioningManagerInstance;

	// Initialization
	PartitioningManager(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects, SceneObject* grid);
	PartitioningManager(PartitioningManager const&) = delete;
	PartitioningManager operator=(PartitioningManager const&) = delete;

public:
	// Initialization
	static PartitioningManager* GetInstance(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects, SceneObject* grid);

	// Update
	void Update();

	// Accessors
	PartitionGrid* GetPartitionGrid() { return partitionGridPtr; }

	// Clean Up
	~PartitioningManager();
};

#endif