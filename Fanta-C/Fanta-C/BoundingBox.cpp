#pragma region Dependencies
// My Headers
#include "BoundingBox.h"		// Connection to declarations
#include "ObjectManager.h"
#pragma endregion

#pragma region Public Interface
void BoundingBox::AddCollidingObject(ObjectManager* collidingObject)
{
	// If object is not in container, add it
	if (!CheckIfObjectInContainer(collidingObject))
		collidingObjects[collidingObject->GetUniqueID()] = collidingObject;
}
void BoundingBox::CalculateMinMax(XMVECTOR* myPosition)
{
	// XYZ
	for (boundingIterators[1] = 0; boundingIterators[1] < 3; ++boundingIterators[1])
	{
		// Assign min
		minMax[0].m128_f32[boundingIterators[1]] = myPosition->m128_f32[boundingIterators[1]] - extents.m128_f32[boundingIterators[1]];

		// Assign max										
		minMax[1].m128_f32[boundingIterators[1]] = myPosition->m128_f32[boundingIterators[1]] + extents.m128_f32[boundingIterators[1]];
	}
}
bool BoundingBox::CheckIfObjectInContainer(ObjectManager* collidingObject)
{
	// If object is in the container
	if (collidingObjects.find(collidingObject->GetUniqueID()) != collidingObjects.end())
		return true;

	// If object is not in the container
	return false;
}
#pragma endregion
void BoundingBox::RemoveCollidingObject(ObjectManager* removeObject)
{
	collidingObjects.erase(removeObject->GetUniqueID());
}

#pragma region Private
void BoundingBox::CreateBounds(float inDepth, float inHeight, float inWidth, float inScale)
{
	const float flatMeshWidth = 0.05f;

	// Creates cube or square (if flat)
	extents.m128_f32[0] = (inWidth == 0) ? flatMeshWidth : inWidth * inScale;
	extents.m128_f32[1] = (inHeight == 0) ? flatMeshWidth : inHeight * inScale;
	extents.m128_f32[2] = (inDepth == 0) ? flatMeshWidth : inDepth * inScale;
	extents.m128_f32[3] = 1;
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
