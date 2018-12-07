#pragma region Dependencies
// My Headers
#include "CollisionManager.h"			// Connection to declarations

#include "BoundingBoxCollision.h"
#include "PartitionGrid.h"
#include "PartitioningManager.h"
#include "SceneManager.h"
#pragma endregion

#pragma region Forward Declarations
CollisionManager* CollisionManager::collisionManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
CollisionManager::CollisionManager(SceneObject* grid)
{
	boundingBoxCollisionPtr = BoundingBoxCollision::GetInstance(); 
	partitioningManagerPtr = PartitioningManager::GetInstance(grid);
}
#pragma endregion

#pragma region Update
void CollisionManager::Update(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects)
{
	partitioningManagerPtr->Update(collidableObjects);
	boundingBoxCollisionPtr->Update(partitioningManagerPtr->GetPartitionGrid());
}
#pragma endregion

#pragma region Accessors
CollisionManager * CollisionManager::GetInstance(SceneObject * grid)
{
	// If instance is already created, return it
	if (collisionManagerInstance) return collisionManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		collisionManagerInstance = new CollisionManager(grid);
		return collisionManagerInstance;
	}
}
#pragma endregion

#pragma region Clean Up
CollisionManager::~CollisionManager()
{
	if (boundingBoxCollisionPtr) delete boundingBoxCollisionPtr; 
	if (partitioningManagerPtr) delete partitioningManagerPtr;
}
#pragma endregion
