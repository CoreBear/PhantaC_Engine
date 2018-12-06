#pragma region Dependencies
// My Headers
#include "Partitioner.h"			// Connection to declarations

#include "PartitionCell.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
Partitioner* Partitioner::partitionerInstance = nullptr;
#pragma endregion

#pragma region Update
void Partitioner::Update(std::vector<SceneObject*>* collidableObject, std::vector<PartitionCell*>* gridCells)
{
	// Add objects to cells
	// For each cell
	for (iterators[0] = 0; iterators[0] < gridCells->size(); ++iterators[0])
	{
		// For each collidable object
		for (iterators[1] = 0; iterators[1] < collidableObject->size(); ++iterators[1])
		{
			// If collidable object is inside of the cell's area
			if (gridCells->at(iterators[0])->IsObjectInsideOfMyArea(collidableObject->at(iterators[1])))
			{
				// Add object to cell's container. A check is being done on the other side
				gridCells->at(iterators[0])->AddObject(collidableObject->at(iterators[1]));
			}

			// If object is not inside the cell's area
			else
			{
				// Remove object from cell's container. A check is being done on the other side
				gridCells->at(iterators[0])->RemoveObject(collidableObject->at(iterators[1]));
			}
		}
	}
}
#pragma endregion

#pragma region Accessors
Partitioner * Partitioner::GetInstance()
{
	// If instance is already created, return it
	if (partitionerInstance) return partitionerInstance;

	// If instance has not been created, create it and return it
	else
	{
		partitionerInstance = new Partitioner;
		return partitionerInstance;
	}
}
#pragma endregion