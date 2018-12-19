#pragma region Dependencies
// My Headers
#include "PartitioningManager.h"		// Connection to declarations

#include "PartitionGrid.h"
#include "Partitioner.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
PartitioningManager* PartitioningManager::partitioningManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
PartitioningManager::PartitioningManager(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects, SceneObject* grid)
{
	partitionGridPtr = PartitionGrid::GetInstance(grid);
	partitionerPtr = Partitioner::GetInstance(collidableObjects, partitionGridPtr);
}
PartitioningManager* PartitioningManager::GetInstance(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects, SceneObject* grid)
{
	// If instance is already created, return it
	if (partitioningManagerInstance) return partitioningManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		partitioningManagerInstance = new PartitioningManager(collidableObjects, grid);
		return partitioningManagerInstance;
	}
}
#pragma endregion

#pragma region Update
void PartitioningManager::Update()
{
	partitionerPtr->Update();
}
#pragma endregion

#pragma region Clean Up
PartitioningManager::~PartitioningManager()
{
	if (partitionGridPtr) delete partitionGridPtr;
	if (partitionerPtr) delete partitionerPtr;
}
#pragma endregion
