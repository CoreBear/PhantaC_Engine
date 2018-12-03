#pragma region Dependencies
// My Headers
#include "CollisionManager.h"			// Connection to declarations

#include "PartitionGrid.h"
#include "BoundingBoxCollision.h"
#include "PartitioningManager.h"
#pragma endregion

#pragma region Initialization
CollisionManager::CollisionManager(ObjectManager* grid)
{
	boundingBoxCollisionPtr = new BoundingBoxCollision; 
	partitioningManagerPtr = new PartitioningManager(grid);
}
#pragma endregion

#pragma region Update
void CollisionManager::Update(std::vector<ObjectManager*>* collidableObject)
{
	partitioningManagerPtr->Update(collidableObject);
	boundingBoxCollisionPtr->Update(partitioningManagerPtr->GetPartitionGrid()->GetGridCells());
}
#pragma endregion

#pragma region Clean Up
CollisionManager::~CollisionManager()
{
	if (boundingBoxCollisionPtr) delete boundingBoxCollisionPtr; 
	if (partitioningManagerPtr) delete partitioningManagerPtr;
}
#pragma endregion
