#pragma region Dependencies
// My Headers
#include "PartitioningManager.h"		// Connection to declarations

#include "ObjectManager.h"
#include "PartitionGrid.h"
#include "Partitioner.h"
#pragma endregion

#pragma region Initialization
PartitioningManager::PartitioningManager(ObjectManager* grid)
{
	partitionGridPtr = new PartitionGrid(grid);
	partitionerPtr = new Partitioner;
}
#pragma endregion

#pragma region Update
void PartitioningManager::Update(std::vector<ObjectManager*>* collidableObjects)
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
