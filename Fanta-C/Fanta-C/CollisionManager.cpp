#pragma region Dependencies
// My Headers
#include "CollisionManager.h"			// Connection to declarations

#include "ObjectManager.h"
#pragma endregion

#pragma region Update
void CollisionManager::Update(std::vector<ObjectManager*>* collidableObject)
{
	// For each collidable game object
	for (collisionIterators[0] = 0; collisionIterators[0] < collidableObject->size(); ++collisionIterators[0])
	{
		// The object being checked against all other objects (collider)
		objectsBeingChecked[0] = collidableObject->at(collisionIterators[0]);

		// For each collidable game object
		for (collisionIterators[1] = 0; collisionIterators[1] < collidableObject->size(); ++collisionIterators[1])
		{
			// If current game object is not the collider (see parentheses above)
			if (collidableObject->at(collisionIterators[1]) != objectsBeingChecked[0])
			{
				// Assign collidee
				objectsBeingChecked[1] = collidableObject->at(collisionIterators[1]);

				// Collider and collidee
				for (collisionIterators[2] = 0; collisionIterators[2] < 2; ++collisionIterators[2])
				{
					// XYZ
					for (collisionIterators[3] = 0; collisionIterators[3] < 3; ++collisionIterators[3])
					{
						// Assign the collider and collidee minimums
						min[collisionIterators[2]].m128_f32[collisionIterators[3]] = 
						objectsBeingChecked[collisionIterators[2]]->GetTransform()->GetPosition().m128_f32[collisionIterators[3]] -
						objectsBeingChecked[collisionIterators[2]]->GetCollider()->GetExtents().m128_f32[collisionIterators[3]];

						// Assign the collider and collidee maximums
						max[collisionIterators[2]].m128_f32[collisionIterators[3]] = 
						objectsBeingChecked[collisionIterators[2]]->GetTransform()->GetPosition().m128_f32[collisionIterators[3]] +
						objectsBeingChecked[collisionIterators[2]]->GetCollider()->GetExtents().m128_f32[collisionIterators[3]];
					}
				}
				
				// Set is colliding to true, because the goal is to disprove the collision
				isColliding = true;

				// XYZ
				for (collisionIterators[2] = 0; collisionIterators[2] < 3; ++collisionIterators[2])
				{
					// If only one axis is not colliding, then there is no collision
					if (max[0].m128_f32[collisionIterators[2]] < min[1].m128_f32[collisionIterators[2]] ||
						min[0].m128_f32[collisionIterators[2]] > max[1].m128_f32[collisionIterators[2]])
					{
						// Only one axis does not need to overlap for non-collision
						isColliding = false;

						// Stop checking for collision
						break;
					}
				}

				// If collision is occuring
				if (isColliding)
				{
					// If collider wasn't previously colliding
					if (!objectsBeingChecked[0]->GetCollider()->GetColliding())
					{
						// Change colliding flag
						objectsBeingChecked[0]->GetCollider()->ToggleColliding();

						// Change color
						objectsBeingChecked[0]->GetMesh()->ChangeColor(Colors::Red);
					}

					// If object is not in container, add it
					if (!objectsBeingChecked[0]->GetCollider()->CheckIfObjectInContainer(objectsBeingChecked[1]))
						objectsBeingChecked[0]->GetCollider()->AddCollidingObject(objectsBeingChecked[1]);
				}

				// If no collision is occuring
				else
				{
					// If object is not in container, add it
					if (objectsBeingChecked[0]->GetCollider()->CheckIfObjectInContainer(objectsBeingChecked[1]))
						objectsBeingChecked[0]->GetCollider()->RemoveCollidingObject(objectsBeingChecked[1]);
					
					// If collider was previously colliding
					if (objectsBeingChecked[0]->GetCollider()->GetColliding())
					{
						// If no collidee in collider's container
						if (objectsBeingChecked[0]->GetCollider()->ContainerEmpty())
						{
							// Change colliding flag
							objectsBeingChecked[0]->GetCollider()->ToggleColliding();

							// Change color
							objectsBeingChecked[0]->GetMesh()->ChangeColor(Colors::Green);
						}
					}
				}
			}
		}
	}
}
#pragma endregion