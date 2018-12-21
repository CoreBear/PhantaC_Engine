#pragma region Dependencies
// My Headers
#include "PartitionGrid.h"		// Connection to declarations

#include "Grid.h"
#include "SceneObject.h"
#include "PartitionCell.h"
#pragma endregion

#pragma region Forward Declarations
PartitionGrid* PartitionGrid::partitionGridInstance = nullptr;
#pragma endregion

#pragma region Initialization
PartitionGrid::PartitionGrid(SceneObject* grid)
{
	if (grid)
	{
		// Edge distance from center
		float edgeDistance = static_cast<Grid*>(grid->GetMesh())->GetEdgeOfGridDistance();

		// Positions for cell creation
		float position[2] = { -edgeDistance, -edgeDistance };

		const uchar XZAxes = 2;
		const uchar numberOfCellsInEachDirection = 10;
		const float cellDepthWidth = (edgeDistance * XZAxes) / numberOfCellsInEachDirection;
		numberOfTotalCells = numberOfCellsInEachDirection * numberOfCellsInEachDirection;
		gridCells = new PartitionCell[numberOfTotalCells];

		// Z Axis
		for (uchar zIterator = 0, indexer = 0, xIterator; zIterator < numberOfCellsInEachDirection; ++zIterator)
		{
			// X Axis
			for (xIterator = 0; xIterator < numberOfCellsInEachDirection; ++xIterator)
			{
				gridCells[indexer++].DelayedInitialization(position[0], position[1], position[0] + cellDepthWidth, position[1] + cellDepthWidth);

				// Update x-axis position to shift to next cell
				position[0] += cellDepthWidth;
			}

			// Update positions
			// Move x-axis position back to the beginning
			position[0] = -edgeDistance;

			// Move y-axis position up one
			position[1] += cellDepthWidth;
		}
	}
}
PartitionGrid * PartitionGrid::GetInstance(SceneObject * grid)
{
	// If instance is already created, return it
	if (partitionGridInstance) return partitionGridInstance;

	// If instance has not been created, create it and return it
	else
	{
		partitionGridInstance = new PartitionGrid(grid);
		return partitionGridInstance;
	}
}
#pragma endregion