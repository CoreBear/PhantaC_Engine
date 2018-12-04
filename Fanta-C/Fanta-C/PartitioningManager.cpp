#pragma region Dependencies
// My Headers
#include "PartitioningManager.h"		// Connection to declarations

#include "PartitionGrid.h"
#include "Partitioner.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Initialization
PartitioningManager::PartitioningManager(SceneObject* grid)
{
	partitionGridPtr = new PartitionGrid(grid);
	partitionerPtr = new Partitioner;
}
#pragma endregion

#pragma region Update
void PartitioningManager::Update(std::vector<SceneObject*>* collidableObjects)
{
	partitionerPtr->Update(collidableObjects, partitionGridPtr->GetGridCells());
}
#pragma endregion

#pragma region Clean Up
PartitioningManager::~PartitioningManager()
{
	if (partitionGridPtr) delete partitionGridPtr;
	if (partitionerPtr) delete partitionerPtr;
}
#pragma endregion
