#pragma region Dependencies
// My Headers
#include "PartitionCell.h"		// Connection to declarations

#include "GlobalMath.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Initialization
void PartitionCell::DelayedInitialization(float minX, float minZ, float maxX, float maxZ)
{
	mins[0] = minX;
	mins[1] = minZ;
	maxs[0] = maxX;
	maxs[1] = maxZ;
}
#pragma endregion

#pragma region Public Interface
void PartitionCell::AddObject(SceneObject* inObject)
{
	// If object is not inside of this cell, add it to container
	if (!IsObjectInsideOfMyContainer(inObject))
		objectsInsideOfMyContainer.AddToBack(inObject);
}
bool PartitionCell::IsObjectInsideOfMyArea(SceneObject* checkObject)
{
	// Update check object's min max
	checkObject->GetColliderManager()->GetBoundingBox()->CalculateMinMax(checkObject->GetTransform()->GetLocalMatrix(), &checkObjectsMinMax[0], &checkObjectsMinMax[1]);
	
	// If check object's x-axis position is greater than cell's x min and less than cell's 
	// x max and the same for the z-axis, but top and bottom, check object is inside of cell
	if (checkObjectsMinMax[1].m128_f32[0] > mins[0] && checkObjectsMinMax[0].m128_f32[0] < maxs[0] &&
		checkObjectsMinMax[1].m128_f32[2] > mins[1] && checkObjectsMinMax[0].m128_f32[2] < maxs[1])
		return true;

	// If not inside of cell
	return false;
}
bool PartitionCell::IsObjectInsideOfMyContainer(SceneObject* checkObject)
{
	// If this object exists in map, return true
	if (objectsInsideOfMyContainer.Contains(checkObject))
		return true;

	// If this object does not exist in map, return false
	return false;
}
void PartitionCell::RemoveObject(SceneObject* removedObject)
{
	// If object is inside of this cell, remove it
	if (IsObjectInsideOfMyContainer(removedObject))
		objectsInsideOfMyContainer.Remove(removedObject);
}
void PartitionCell::VerifyOrRemoveObjectsFromContainer()
{
	// For each object inside of cell
	for (iterator = 0; iterator < objectsInsideOfMyContainer.GetSize(); ++iterator)
	{
		// If object is no longer in cell's area, remove it from its container
		if (!IsObjectInsideOfMyArea(objectsInsideOfMyContainer.At(iterator)))
			RemoveObject(objectsInsideOfMyContainer.At(iterator));
	}
}
#pragma endregion