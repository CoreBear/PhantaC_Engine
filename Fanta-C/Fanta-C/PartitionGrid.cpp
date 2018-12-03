#pragma region Dependencies
// My Headers
#include "PartitionGrid.h"		// Connection to declarations

#include "Grid.h"
#include "ObjectManager.h"
#include "PartitionCell.h"
#pragma endregion

#pragma region Initialization
PartitionGrid::PartitionGrid(ObjectManager* grid)
{
	// Edge distance from center
	float edgeDistance = static_cast<Grid*>(grid->GetMesh())->GetEdgeOfGridDistance();

	// Positions for cell creation
	float position[2] = { -edgeDistance, -edgeDistance };
	
	const float numberOfCellsInEachDirection = 7;
	const float cellDepthWidth = (edgeDistance * 2) / numberOfCellsInEachDirection;

	PartitionCell* newCell;

	// -1, because the the precision error adds more unwanted cells on the end
	// Generate an unknown amount of cells on y-axis
	while (position[1] < edgeDistance - 1)
	{
		// Generate an unknown amount of cells on x-axis
		while (position[0] < edgeDistance - 1)
		{
			// Create new cell, populate information, add to vector
			newCell = new PartitionCell(position[0], position[1], cellDepthWidth, cellDepthWidth);
			gridCells.push_back(newCell);
			
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
#pragma endregion

#pragma region Clean Up
PartitionGrid::~PartitionGrid()
{
	for (ushort i = 0; i < gridCells.size(); ++i)
		delete gridCells.at(i);
}
#pragma endregion
