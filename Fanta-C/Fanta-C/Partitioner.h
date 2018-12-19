#ifndef _PARTITIONER_H
#define _PARTITIONER_H

// My Headers
#include "GlobalSceneVariables.h"
#include "GlobalTypedefs.h"
#include "MyArray.h"

// Forward Declarations
class PartitionGrid;
class SceneObject;

class Partitioner
{
	// Variables
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>*	collidableObjects;
	PartitionGrid*															grid;
	static Partitioner*														partitionerInstance;
	ushort																	iterators[2];

	// Initialization
	Partitioner(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* inCollidableObjects, PartitionGrid* inGrid) : collidableObjects(inCollidableObjects), grid(inGrid) { return; }
	Partitioner(Partitioner const&) = delete;
	Partitioner operator=(Partitioner const&) = delete;

public:
	// Initialization
	static Partitioner* GetInstance(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* inCollidableObjects, PartitionGrid* inGrid);

	// Update
	void Update();
};

#endif