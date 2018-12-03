#pragma region Dependencies
// My Headers
#include "Partitioner.h"			// Connection to declarations

#include "ObjectManager.h"
#include "PartitionCell.h"
#pragma endregion

#pragma region Update
void Partitioner::Update(std::vector<ObjectManager*>* collidableObject, std::vector<PartitionCell*>* gridCells)
{
	// Remove objects from cells
	// For each cell
	//for (iterators[0] = 0; iterators[0] < gridCells->size(); ++iterators[0])
	//{
	//	// Check to see if there are objects in container that are no longer 
	//	// physically in cell's space. If ther are, remove them
	//	gridCells->at(iterators[0])->VerifyOrRemoveObjectsFromContainer();
	//}

	// Add objects to cells
	// For each cell
	for (iterators[1] = 0; iterators[1] < gridCells->size(); ++iterators[1])
	{
		// For each collidable object
		for (iterators[0] = 0; iterators[0] < collidableObject->size(); ++iterators[0])
		{
			// If collidable object is inside of the cell's area
			if (gridCells->at(iterators[1])->IsObjectInsideOfMyArea(collidableObject->at(iterators[0])))
			{
				// Add object to cell's container. A check is being done on the other side
				gridCells->at(iterators[1])->AddObject(collidableObject->at(iterators[0]));
			}

			// If object is not inside the cell's area
			else
			{
				// Remove object from cell's container. A check is being done on the other side
				gridCells->at(iterators[1])->RemoveObject(collidableObject->at(iterators[0]));
			}
		}
	}
}
#pragma endregion
