#pragma region Dependencies
// My Headers
#include "PartitionCell.h"		// Connection to declarations

#include "GlobalMath.h"
#include "ObjectManager.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Initialization
void PartitionCell::AddObject(SceneObject* inObject)
{
	// If object is not inside of this cell, add it to container
	if (!IsObjectInsideOfMyContainer(inObject))
		objectsInsideOfMyContainer.push_back(inObject);
}
bool PartitionCell::IsObjectInsideOfMyArea(SceneObject* checkObject)
{
	// Update check object's min max
	checkObject->GetMyObject()->GetColliderManager()->GetBoundingBox()->CalculateMinMax(checkObject->GetMyObject()->GetTransform()->GetLocalMatrix(), &checkObjectsMinMax[0], &checkObjectsMinMax[1]);
	
	// If check object's x-axis position is greater than cell's left edge position and less than cell's 
	// right edge position and the same for the y-axis, but top and bottom, check object is inside of cell
	if (checkObjectsMinMax[1].m128_f32[0] > myPosition.m128_f32[0] && checkObjectsMinMax[0].m128_f32[0] < myPosition.m128_f32[0] + dimensions[0] &&
		checkObjectsMinMax[1].m128_f32[2] > myPosition.m128_f32[2] && checkObjectsMinMax[0].m128_f32[2] < myPosition.m128_f32[2] + dimensions[1])
		return true;

	// If not inside of cell
	return false;
}
bool PartitionCell::IsObjectInsideOfMyContainer(SceneObject* checkObject)
{
	// If this object exists in map, return true
	if (std::find(objectsInsideOfMyContainer.begin(), objectsInsideOfMyContainer.end(), checkObject) != objectsInsideOfMyContainer.end())
		return true;

	// If this object does not exist in map, return false
	return false;
}
void PartitionCell::RemoveObject(SceneObject* removedObject)
{
	// If object is inside of this cell, remove it
	if (IsObjectInsideOfMyContainer(removedObject))
		objectsInsideOfMyContainer.erase(std::remove(objectsInsideOfMyContainer.begin(), objectsInsideOfMyContainer.end(), removedObject), objectsInsideOfMyContainer.end());
}
void PartitionCell::VerifyOrRemoveObjectsFromContainer()
{
	// For each object inside of cell
	for (iterator = 0; iterator < objectsInsideOfMyContainer.size(); ++iterator)
	{
		// If object is no longer in cell's area, remove it from its container
		if (!IsObjectInsideOfMyArea(objectsInsideOfMyContainer.at(iterator)))
			RemoveObject(objectsInsideOfMyContainer.at(iterator));
	}
}
#pragma endregion
