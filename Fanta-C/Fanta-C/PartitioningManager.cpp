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
PartitioningManager::PartitioningManager(SceneObject* grid)
{
	partitionGridPtr = PartitionGrid::GetInstance(grid);
	partitionerPtr = Partitioner::GetInstance();
}
#pragma endregion

#pragma region Update
void PartitioningManager::Update(std::vector<SceneObject*>* collidableObjects)
{
	partitionerPtr->Update(collidableObjects, partitionGridPtr->GetGridCells());
}
#pragma endregion

#pragma region Accessors
PartitioningManager * PartitioningManager::GetInstance(SceneObject * grid)
{
	// If instance is already created, return it
	if (partitioningManagerInstance) return partitioningManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		partitioningManagerInstance = new PartitioningManager(grid);
		return partitioningManagerInstance;
	}
}
#pragma endregion

#pragma region Clean Up
PartitioningManager::~PartitioningManager()
{
	if (partitionGridPtr) delete partitionGridPtr;
	if (partitionerPtr) delete partitionerPtr;
}
#pragma endregion
