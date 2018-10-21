#pragma region Dependencies
// My Headers
#include "Grid.h"				// Connection to declarations
#include "GlobalApplication.h"
#include "GlobalGeometry.h"
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Grid::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; iterators[0] += 2)
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[iterators[0] + 1].localPos,
								vertices[iterators[0]].color, vertices[iterators[0] + 1].color);
}
#pragma endregion

#pragma region Private
void Grid::CreateShape()
{
	uchar		lineDistanceApart = 1;
	ushort		numberOfLinesTotal = ushort(numberOfVertices * 0.5f);				
	ushort		numberOfLinesEachDirection = ushort(numberOfLinesTotal * 0.5f);		
	ushort		integerHalfOfLinesEachDirection = numberOfLinesEachDirection * 0.5f;
	float		endPoint = (numberOfLinesEachDirection % 2 == 0) ? integerHalfOfLinesEachDirection * lineDistanceApart - (0.5f * lineDistanceApart) : integerHalfOfLinesEachDirection * lineDistanceApart;
	float		offset = (numberOfLinesEachDirection % 2 == 0) ? 0.5f : 0;
	ushort		vertCount;														    
	XMFLOAT3	tempVertex;

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
					tempVertex.x = (iterators[2]) ? -endPoint : endPoint;
					tempVertex.y = 0;
					tempVertex.z = (iterators[1] - integerHalfOfLinesEachDirection) * lineDistanceApart + (offset * lineDistanceApart);
				}

				// Vertical lines
				else
				{
					// Top to bottom
					tempVertex.x = (iterators[1] - integerHalfOfLinesEachDirection) * lineDistanceApart + (offset * lineDistanceApart);
					tempVertex.y = 0;
					tempVertex.z = (iterators[2]) ? -endPoint : endPoint;
				}

				// Add lines to drawable vertices and color them
				vertices[vertCount].localPos = tempVertex;
				vertices[vertCount++].color = Colors::White;
			}
		}
	}
}
#pragma endregion