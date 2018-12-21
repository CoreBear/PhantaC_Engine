#pragma region Dependencies
// My Headers
#include "Grid.h"				// Connection to declarations
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Grid::AddMyLinesToRenderer(LineRenderer* lineRenderer)
{
	for (reusableIterator = 0; reusableIterator < numberOfVertices; reusableIterator += 2)
		lineRenderer->AddNewLine(vertices[reusableIterator].localPos, vertices[reusableIterator + 1].localPos, color, color);
}
#pragma endregion

#pragma region Private
void Grid::CreateMesh()
{
	ushort		numberOfLinesTotal = ushort(numberOfVertices * 0.5f);				
	ushort		numberOfLinesEachDirection = ushort(numberOfLinesTotal * 0.5f);		
	ushort		integerHalfOfLinesEachDirection = ushort(numberOfLinesEachDirection * 0.5f);
	float		offset = (numberOfLinesEachDirection % 2 == 0) ? 0.5f : 0;
	ushort		iterators[2];
	ushort		vertCount;		
	XMVECTOR	tempVertex;
	
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
					tempVertex.m128_f32[0] = (iterators[1]) ? -edgeOfGridDistance : edgeOfGridDistance;
					tempVertex.m128_f32[1] = 0;
					tempVertex.m128_f32[2] = (iterators[0] - integerHalfOfLinesEachDirection) * lineDistanceApart + (offset * lineDistanceApart);
				}

				// Vertical lines
				else
				{
					// Top to bottom
					tempVertex.m128_f32[0] = (iterators[0] - integerHalfOfLinesEachDirection) * lineDistanceApart + (offset * lineDistanceApart);
					tempVertex.m128_f32[1] = 0;
					tempVertex.m128_f32[2] = (iterators[1]) ? -edgeOfGridDistance : edgeOfGridDistance;
				}

				// Add lines to drawable vertices and color them
				vertices[vertCount++].localPos = tempVertex;
			}
		}
	}
}
#pragma endregion