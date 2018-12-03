#pragma region Dependencies
// My Headers
#include "BoundingBoxCollision.h"		// Connection to declarations

#include "BoundingBox.h"
#include "ObjectManager.h"
#include "PartitionCell.h"
#pragma endregion

#pragma region Update
void BoundingBoxCollision::AssignCollisionObjects(std::vector<ObjectManager*>* collidableObjects)
{
	// For each collidable game object
	for (collisionIterators[1] = 0; collisionIterators[1] < collidableObjects->size(); ++collisionIterators[1])
	{
		// The collider being checked against all other collidees
		objectsBeingChecked[0] = collidableObjects->at(collisionIterators[1]);
		boxBeingChecked[0] = objectsBeingChecked[0]->GetColliderManager()->GetBoundingBox();

		// For each collidable game object
		for (collisionIterators[2] = 0; collisionIterators[2] < collidableObjects->size(); ++collisionIterators[2])
		{
			// If collider position is not the same as collidee position
			if (collisionIterators[1] != collisionIterators[2])
			{
				// Assign collidee
				objectsBeingChecked[1] = collidableObjects->at(collisionIterators[2]);
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
			// If collidee is in container, remove it
			if (boxBeingChecked[0]->CheckIfObjectInContainer(objectsBeingChecked[1]))
				boxBeingChecked[0]->RemoveCollidingObject(objectsBeingChecked[1]);

			// If collider was previously colliding
			if (boxBeingChecked[0]->GetColliding())
			{
				// If no collidee in collider's container
				if (boxBeingChecked[0]->ContainerEmpty())
				{
					// Change colliding flag
					boxBeingChecked[0]->ToggleColliding();

					// Change color
					objectsBeingChecked[0]->GetMesh()->ChangeColor(Colors::Green);
				}
			}

			// Stop checking for collision. No collision occuring
			return;
		}
	}

	// If code makes it here, collision is occuring

	// If colliderManager wasn't previously colliding
	if (!boxBeingChecked[0]->GetColliding())
	{
		// Change colliding flag
		boxBeingChecked[0]->ToggleColliding();

		// Change color
		objectsBeingChecked[0]->GetMesh()->ChangeColor(Colors::Red);
	}

	// If collidee is not in container, add it
	if (!boxBeingChecked[0]->CheckIfObjectInContainer(objectsBeingChecked[1]))
		boxBeingChecked[0]->AddCollidingObject(objectsBeingChecked[1]);
}
void BoundingBoxCollision::Update(std::vector<PartitionCell*>* gridCells)
{
	// For each cell
	for (collisionIterators[0] = 0; collisionIterators[0] < gridCells->size(); ++collisionIterators[0])
	{
		// If there is more than one object in cell, run collision on all objects in cell
		if (gridCells->at(collisionIterators[0])->GetObjectsInsideOfMe()->size() > 1)
			AssignCollisionObjects(gridCells->at(collisionIterators[0])->GetObjectsInsideOfMe());
	}
}
#pragma endregion