#pragma region Dependencies
// My Headers
#include "BoundingBox.h"		// Connection to declarations

#include "GlobalMath.h"
#include "SceneObject.h"
#pragma endregion

extern const char* stuff;

#pragma region Public Interface
void BoundingBox::AddCollidingObject(SceneObject* collidingObject)
{
	// If object is not in container, add it
	if (!CheckIfObjectInContainer(collidingObject))
		collidingObjects[collidingObject->GetUniqueID()] = collidingObject;
}
void BoundingBox::CalculateMinMax(XMMATRIX* myLocalMatrix, XMVECTOR* min, XMVECTOR* max)
{
	const static float center = 0.62f; // Figure out why 0.5f doesn't work here
	const static uchar doubleValue = 2;
	const static uchar inverse = 1;

	#pragma region X - Axis
	// Assign min
	minMax[0].m128_f32[0] = min->m128_f32[0] = myLocalMatrix->r[3].m128_f32[0] -
		GlobalMath::Lerp(extents.m128_f32[0], maxDiag[1], inverse - (doubleValue * GlobalMath::AbsoluteValue(center - GlobalMath::AbsoluteValue(myLocalMatrix->r[0].m128_f32[0]))));

	// Assign max										
	minMax[1].m128_f32[0] = max->m128_f32[0] = myLocalMatrix->r[3].m128_f32[0] + 
		GlobalMath::Lerp(extents.m128_f32[0], maxDiag[1], inverse - (doubleValue * GlobalMath::AbsoluteValue(center - GlobalMath::AbsoluteValue(myLocalMatrix->r[0].m128_f32[0]))));
	#pragma endregion

	#pragma region Y - Axis
	// Assign min
	minMax[0].m128_f32[1] = min->m128_f32[1] = myLocalMatrix->r[3].m128_f32[1] - 
		GlobalMath::Lerp(extents.m128_f32[1], maxDiag[1], inverse - (doubleValue * GlobalMath::AbsoluteValue(center - GlobalMath::AbsoluteValue(myLocalMatrix->r[1].m128_f32[1]))));

	// Assign max										
	minMax[1].m128_f32[1] = max->m128_f32[1] = myLocalMatrix->r[3].m128_f32[1] + 
		GlobalMath::Lerp(extents.m128_f32[1], maxDiag[1], inverse - (doubleValue * GlobalMath::AbsoluteValue(center - GlobalMath::AbsoluteValue(myLocalMatrix->r[1].m128_f32[1]))));
	#pragma endregion

	#pragma region Z - Axis
	// Assign min
	minMax[0].m128_f32[2] = min->m128_f32[2] = myLocalMatrix->r[3].m128_f32[2] - 
		GlobalMath::Lerp(extents.m128_f32[2], maxDiag[0], inverse - (doubleValue * GlobalMath::AbsoluteValue(center - GlobalMath::AbsoluteValue(myLocalMatrix->r[2].m128_f32[2]))));

	// Assign max										
	minMax[1].m128_f32[2] = max->m128_f32[2] = myLocalMatrix->r[3].m128_f32[2] + 
		GlobalMath::Lerp(extents.m128_f32[2], maxDiag[0], inverse - (doubleValue * GlobalMath::AbsoluteValue(center - GlobalMath::AbsoluteValue(myLocalMatrix->r[2].m128_f32[2]))));
	#pragma endregion
}
bool BoundingBox::CheckIfObjectInContainer(SceneObject* collidingObject)
{
	// If object is in the container
	if (collidingObjects.find(collidingObject->GetUniqueID()) != collidingObjects.end())
		return true;

	// If object is not in the container
	return false;
}
#pragma endregion
void BoundingBox::RemoveCollidingObject(SceneObject* removeObject)
{
	if (CheckIfObjectInContainer(removeObject))
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

	// Generates max diagonal widths
	maxDiag[0] = sqrt((extents.m128_f32[0] * extents.m128_f32[0]) + (extents.m128_f32[2] * extents.m128_f32[2]));	// XZ
	maxDiag[1] = sqrt((extents.m128_f32[0] * extents.m128_f32[0]) + (extents.m128_f32[1] * extents.m128_f32[1]));	// Y
}
#pragma endregion

#pragma region Mutators
void BoundingBox::SetExtents(float inWidth, float inHeight, float inDepth)
{
	const float flatMeshWidth = 0.05f;

	// This is wrong...look into scale
	extents.m128_f32[0] = (inWidth == 0) ? flatMeshWidth : inWidth;
	extents.m128_f32[1] = (inHeight == 0) ? flatMeshWidth : inHeight;
	extents.m128_f32[2] = (inDepth == 0) ? flatMeshWidth : inDepth;

	// Generates max diagonal widths
	maxDiag[0] = sqrt((extents.m128_f32[0] * extents.m128_f32[0]) + (extents.m128_f32[2] * extents.m128_f32[2]));	// XZ
	maxDiag[1] = sqrt((extents.m128_f32[0] * extents.m128_f32[0]) + (extents.m128_f32[1] * extents.m128_f32[1]));	// Y
}
#pragma endregion
