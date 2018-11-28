#pragma region Dependencies
// My Headers
#include "BoundingBox.h"		// Connection to declarations
#include "ObjectManager.h"
#pragma endregion

#pragma region Public Interface
bool BoundingBox::CheckIfObjectInContainer(ObjectManager* collidingObject)
{
	// Search every object in container
	for (boundingIterator = 0; boundingIterator < collidingObjects.size(); ++boundingIterator)
	{
		// If object is in the container, let caller know
		if (collidingObject == collidingObjects.at(boundingIterator))
			return true;
	}

	// If object is not in the container, let caller know
	return false;
}
#pragma endregion
void BoundingBox::RemoveCollidingObject(ObjectManager* removeObject)
{
	collidingObjects.erase(std::remove(collidingObjects.begin(), collidingObjects.end(), removeObject), collidingObjects.end());
}

#pragma region Private
void BoundingBox::CreateBounds(bool meshIsFlat, float scale)
{
	const float flatMeshWidth = 0.05f;

	// Creates cube or square (if flat)
	extents.m128_f32[0] = scale;
	extents.m128_f32[1] = scale;
	extents.m128_f32[2] = (meshIsFlat) ? flatMeshWidth : scale;
	extents.m128_f32[3] = scale;
}
#pragma endregion

#pragma region Mutators
void BoundingBox::SetExtents(float x, float y, float z)
{
	extents.m128_f32[0] = x;
	extents.m128_f32[1] = y;
	extents.m128_f32[2] = z;
}
#pragma endregion
