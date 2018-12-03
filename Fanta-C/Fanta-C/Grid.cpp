#pragma region Dependencies
// My Headers
#include "Grid.h"				// Connection to declarations
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Grid::AddMyLinesToRenderer(LineRenderer& lineRenderer)
{
	for (reusableIterator = 0; reusableIterator < numberOfVertices; reusableIterator += 2)
		lineRenderer.AddNewLine(vertices[reusableIterator].localPos, vertices[reusableIterator + 1].localPos, color, color);
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
	ushort		iterators[2];
	ushort		vertCount;		
	XMFLOAT3	tempVertex;
	
	edgeOfGridDistance = (numberOfLinesEachDirection % 2 == 0) ? integerHalfOfLinesEachDirection * lineDistanceApart - (0.5f * lineDistanceApart) : integerHalfOfLinesEachDirection * lineDistanceApart;
	
	// Horizontal & Vertical lines
	for (vertCount = 0, reusableIterator = 0; reusableIterator < 2; ++reusableIterator)
	{
		// Number of gridlines per direction
		for (iterators[0] = 0; iterators[0] < numberOfLinesEachDirection; ++iterators[0])
		{
			// Start and end points
			for (iterators[1] = 0; iterators[1] < 2; ++iterators[1])
			{
				// Horizontal lines first
				if (reusableIterator == 0)
				{
					// Left to right
					tempVertex.x = (iterators[1]) ? -edgeOfGridDistance : edgeOfGridDistance;
					tempVertex.y = 0;
					tempVertex.z = (iterators[0] - integerHalfOfLinesEachDirection) * lineDistanceApart + (offset * lineDistanceApart);
				}

				// Vertical lines
				else
				{
					// Top to bottom
					tempVertex.x = (iterators[0] - integerHalfOfLinesEachDirection) * lineDistanceApart + (offset * lineDistanceApart);
					tempVertex.y = 0;
					tempVertex.z = (iterators[1]) ? -edgeOfGridDistance : edgeOfGridDistance;
				}

				// Add lines to drawable vertices and color them
				vertices[vertCount++].localPos = tempVertex;
			}
		}
	}
}
#pragma endregion