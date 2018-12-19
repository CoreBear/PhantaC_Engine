#pragma region Dependencies
// My Headers
#include "BoundingBoxCollision.h"		// Connection to declarations

#include "BoundingBox.h"
#include "GlobalInputVariables.h"
#include "PartitionCell.h"
#include "PartitionGrid.h"
#include "ScriptManager.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
BoundingBoxCollision* BoundingBoxCollision::bbCollisionInstance = nullptr;
#pragma endregion

#pragma region Initialization
BoundingBoxCollision * BoundingBoxCollision::GetInstance()
{
	// If instance is created, return it
	if (bbCollisionInstance) return bbCollisionInstance;

	// If instance has not been created, create it and return it
	else
	{
		bbCollisionInstance = new BoundingBoxCollision;
		return bbCollisionInstance;
	}
}
#pragma endregion

#pragma region Update
void BoundingBoxCollision::Update(PartitionGrid* grid)
{
	// For each cell
	for (collisionIterators[0] = 0; collisionIterators[0] < grid->GetNumberOfTotalCells(); ++collisionIterators[0])
	{
		// If there is more than one object in cell, run collision on all objects in cell
		if (grid->GetGridCells()[collisionIterators[0]].GetObjectsInsideOfMe()->GetSize() > 1)
			AssignCollisionObjects(grid->GetGridCells()[collisionIterators[0]].GetObjectsInsideOfMe());
	}
}
#pragma endregion

#pragma region Private
void BoundingBoxCollision::AssignCollisionObjects(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects)
{
	// For each collidable game object
	for (collisionIterators[1] = 0; collisionIterators[1] < collidableObjects->GetSize(); ++collisionIterators[1])
	{
		// The collider being checked against all other collidees
		objectsBeingChecked[0] = collidableObjects->At(collisionIterators[1]);
		boxBeingChecked[0] = objectsBeingChecked[0]->GetColliderManager()->GetBoundingBox();

		// For each collidable game object
		for (collisionIterators[2] = 0; collisionIterators[2] < collidableObjects->GetSize(); ++collisionIterators[2])
		{
			// If collider position is not the same as collidee position
			if (collisionIterators[1] != collisionIterators[2])
			{
				// Assign collidee
				objectsBeingChecked[1] = collidableObjects->At(collisionIterators[2]);
				boxBeingChecked[1] = objectsBeingChecked[1]->GetColliderManager()->GetBoundingBox();

				CheckForCollision();
			}
		}
	}
}
void BoundingBoxCollision::CheckForCollision()
{
	// XYZ
	for (collisionIterators[3] = 0; collisionIterators[3] < 3; ++collisionIterators[3])
	{
		// If only one axis is not colliding, then there is no collision
		if (boxBeingChecked[0]->GetMinMax(1).m128_f32[collisionIterators[3]] <
			boxBeingChecked[1]->GetMinMax(0).m128_f32[collisionIterators[3]] ||
			boxBeingChecked[0]->GetMinMax(0).m128_f32[collisionIterators[3]] >
			boxBeingChecked[1]->GetMinMax(1).m128_f32[collisionIterators[3]])
		{
			// Remove collidee from container. There's a check on the other side
			boxBeingChecked[0]->RemoveCollidingObject(objectsBeingChecked[1]);

			// If no collidee in collider's container
			if (boxBeingChecked[0]->ContainerEmpty())
			{
				// If collider was previously colliding, change colliding flag
				if (boxBeingChecked[0]->GetColliding())
					boxBeingChecked[0]->ToggleColliding();

				// If object has a script, call its new separation function
				if (!objectsBeingChecked[0]->GetMyScripts()->empty())
					objectsBeingChecked[0]->GetMyScripts()->at(0)->NewSeparation();
			}

			// Stop checking for collision. No collision occuring
			return;
		}
	}

	// IF CODE MAKES IT HERE, COLLISION IS OCCURING!!!

	// Add collidee to container. There's a check on the other side
	boxBeingChecked[0]->AddCollidingObject(objectsBeingChecked[1]);

	// If collider wasn't previously colliding
	if (!boxBeingChecked[0]->GetColliding())
	{
		// If object has a script, call its new collision function
		if (!objectsBeingChecked[0]->GetMyScripts()->empty())
			objectsBeingChecked[0]->GetMyScripts()->at(0)->NewCollision(objectsBeingChecked[1]);

		// Change colliding flag
		boxBeingChecked[0]->ToggleColliding();
	}

	// If collider was previously colliding, pass colliding objects
	else
	{
		// If object has a script, call its continued collision function
		if (!objectsBeingChecked[0]->GetMyScripts()->empty())
			objectsBeingChecked[0]->GetMyScripts()->at(0)->ContinuedCollision(boxBeingChecked[0]->GetCollidingObjects());
	}
}
#pragma endregion