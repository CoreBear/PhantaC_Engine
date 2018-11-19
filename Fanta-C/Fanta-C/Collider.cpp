#pragma region Dependencies
// My Headers
#include "Collider.h"		// Connection to declarations

#include "ObjectManager.h"
#pragma endregion

#pragma region Public Interface
bool Collider::CheckIfObjectInContainer(ObjectManager* collidingObject)
{
	// Search every object in container
	for (colliderIterator = 0; colliderIterator < collidingObjects.size(); ++colliderIterator)
	{
		// If object is in the container, let caller know
		if (collidingObject == collidingObjects.at(colliderIterator))
			return true;
	}

	// If object is not in the container, let caller know
	return false;
}
#pragma endregion
void Collider::RemoveCollidingObject(ObjectManager* removeObject) 
{
	collidingObjects.erase(std::remove(collidingObjects.begin(), collidingObjects.end(), removeObject), collidingObjects.end());
}

#pragma region Private
void Collider::CreateBounds(bool meshIsFlat, float scale)
{	
	const float flatMeshWidth = 0.05f;

	// Creates cube or square (if flat)
	extents.m128_f32[0] = scale;
	extents.m128_f32[1] = scale;
	extents.m128_f32[2] = (meshIsFlat) ? flatMeshWidth : scale;
	extents.m128_f32[3] = scale;
}
#pragma endregion
