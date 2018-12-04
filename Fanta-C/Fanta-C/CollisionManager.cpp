#pragma region Dependencies
// My Headers
#include "CollisionManager.h"			// Connection to declarations

#include "BoundingBoxCollision.h"
#include "PartitionGrid.h"
#include "PartitioningManager.h"
#include "SceneManager.h"
#pragma endregion

#pragma region Initialization
CollisionManager::CollisionManager(SceneObject* grid)
{
	boundingBoxCollisionPtr = new BoundingBoxCollision; 
	partitioningManagerPtr = new PartitioningManager(grid);
}
#pragma endregion

#pragma region Update
void CollisionManager::Update(std::vector<SceneObject*>* collidableObject)
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
