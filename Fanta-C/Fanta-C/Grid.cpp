#pragma region Dependencies
// My Headers
#include "Grid.h"				// Connection to declarations
#include "GlobalIterators.h"
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Grid::AddMyLinesToRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; iterators[0] += 2)
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[iterators[0] + 1].localPos, color, color);
}
#pragma endregion

#pragma region Private
void Grid::CreateMesh()
{
	uchar		lineDistanceApart = 1;
	ushort		numberOfLinesTotal = ushort(numberOfVertices * 0.5f);				
	ushort		numberOfLinesEachDirection = ushort(numberOfLinesTotal * 0.5f);		
	ushort		integerHalfOfLinesEachDirection = ushort(numberOfLinesEachDirection * 0.5f);
	float		offset = (numberOfLinesEachDirection % 2 == 0) ? 0.5f : 0;
	ushort		vertCount;														    
	XMFLOAT3	tempVertex;

	// This is a global variable, found in "GlobalWorldInfo.h". This is used to represent the distance from the world origin to the edge of the grid (X, Y)
	edgeOfGridDistance = (numberOfLinesEachDirection % 2 == 0) ? integerHalfOfLinesEachDirection * lineDistanceApart - (0.5f * lineDistanceApart) : integerHalfOfLinesEachDirection * lineDistanceApart;
	
	// Horizontal & Vertical lines
	for (vertCount = 0, iterators[0] = 0; iterators[0] < 2; ++iterators[0])
	{
		// Number of gridlines per direction
		for (iterators[1] = 0; iterators[1] < numberOfLinesEachDirection; ++iterators[1])
		{
			// Start and end points
			for (iterators[2] = 0; iterators[2] < 2; ++iterators[2])
			{
				// Horizontal lines first
				if (iterators[0] == 0)
				{
					// Left to right
					tempVertex.x = (iterators[2]) ? -edgeOfGridDistance : edgeOfGridDistance;
					tempVertex.y = 0;
					tempVertex.z = (iterators[1] - integerHalfOfLinesEachDirection) * lineDistanceApart + (offset * lineDistanceApart);
				}

				// Vertical lines
				else
				{
					// Top to bottom
					tempVertex.x = (iterators[1] - integerHalfOfLinesEachDirection) * lineDistanceApart + (offset * lineDistanceApart);
					tempVertex.y = 0;
					tempVertex.z = (iterators[2]) ? -edgeOfGridDistance : edgeOfGridDistance;
				}

				// Add lines to drawable vertices and color them
				vertices[vertCount++].localPos = tempVertex;
			}
		}
	}
}
#pragma endregion