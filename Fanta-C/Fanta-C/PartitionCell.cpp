#pragma region Dependencies
// My Headers
#include "PartitionCell.h"		// Connection to declarations

#include "ObjectManager.h"
#pragma endregion

#pragma region Initialization
void PartitionCell::AddObject(ObjectManager* inObject)
{
	// If object is not inside of this cell, add it to container
	if (!IsObjectInsideOfMyContainer(inObject))
		objectsInsideOfMyContainer.push_back(inObject);
}
bool PartitionCell::IsObjectInsideOfMyArea(ObjectManager* checkObject)
{
	// Update check object's min max
	checkObject->GetColliderManager()->GetBoundingBox()->CalculateMinMax(checkObject->GetTransform()->GetPosition());

	// Store check object's min maxs'
	checkObjectsMinMax[0] = checkObject->GetColliderManager()->GetBoundingBox()->GetMinMax(0);
	checkObjectsMinMax[1] = checkObject->GetColliderManager()->GetBoundingBox()->GetMinMax(1);

	// If check object's x-axis position is greater than cell's left edge position and less than cell's 
	// right edge position and the same for the y-axis, but top and bottom, check object is inside of cell
	if (checkObjectsMinMax[1].m128_f32[0] > myPosition.m128_f32[0] && checkObjectsMinMax[0].m128_f32[0] < myPosition.m128_f32[0] + dimensions[0] &&
		checkObjectsMinMax[1].m128_f32[2] > myPosition.m128_f32[2] && checkObjectsMinMax[0].m128_f32[2] < myPosition.m128_f32[2] + dimensions[1])
		return true;

	// If not inside of cell
	return false;
}
bool PartitionCell::IsObjectInsideOfMyContainer(ObjectManager* checkObject)
{
	// If this object exists in map, return true
	if (std::find(objectsInsideOfMyContainer.begin(), objectsInsideOfMyContainer.end(), checkObject) != objectsInsideOfMyContainer.end())
		return true;

	// If this object does not exist in map, return false
	return false;
}
void PartitionCell::RemoveObject(ObjectManager* removedObject)
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
