#pragma region Dependencies
// My Headers
#include "Partitioner.h"			// Connection to declarations

#include "PartitionCell.h"
#include "PartitionGrid.h"
#include "Pooler.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
Partitioner* Partitioner::partitionerInstance = nullptr;
#pragma endregion

#pragma region Initialization
Partitioner* Partitioner::GetInstance(PartitionGrid* inGrid)
{
	// If instance is already created, return it
	if (partitionerInstance) return partitionerInstance;

	// If instance has not been created, create it and return it
	else
	{
		partitionerInstance = new Partitioner(inGrid);
		return partitionerInstance;
	}
}
#pragma endregion

#pragma region Update
void Partitioner::Update()
{
	// Add objects to cells
	// For each cell
	for (iterators[0] = 0; iterators[0] < grid->GetNumberOfTotalCells(); ++iterators[0])
	{
		// For each collidable object
		for (iterators[1] = 0; iterators[1] < Pooler::activeObjects.GetSize(); ++iterators[1])
		{
			if (Pooler::activeObjects.At(iterators[1])->GetCollidable())
			{
				// If collidable object is inside of the cell's area
				if (grid->GetGridCells()[iterators[0]].IsObjectInsideOfMyArea(Pooler::activeObjects.At(iterators[1])))
				{
					// Add object to cell's container. A check is being done on the other side
					grid->GetGridCells()[iterators[0]].AddObject(Pooler::activeObjects.At(iterators[1]));
				}

				// If object is not inside the cell's area
				else
				{
					// Remove object from cell's container. A check is being done on the other side
					grid->GetGridCells()[iterators[0]].RemoveObject(Pooler::activeObjects.At(iterators[1]));
				}
			}
		}
	}
}
#pragma endregion