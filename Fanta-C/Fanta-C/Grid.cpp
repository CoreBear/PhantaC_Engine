#pragma region Dependencies
// My Headers
#include "Grid.h"		// Connection to declarations
#pragma endregion

#pragma region Initialization
Grid::Grid()
{
	uchar		lineDistanceApart = 1;
	ushort		numberOfGridLines = ushort(numberOfVertices * 0.25f);
	ushort		halfGridWidth = ushort(numberOfGridLines * 0.5f);
	ushort		vertCount;
	XMFLOAT3	tempVertex;

	// Horizontal & Vertical lines
	for (vertCount = 0, iterators[0] = 0; iterators[0] < 2; ++iterators[0])
	{
		// Number of gridlines per direction
		for (iterators[1] = 0; iterators[1] < numberOfGridLines; ++iterators[1])
		{
			// Start and end points
			for (iterators[2] = 0; iterators[2] < 2; ++iterators[2])
			{
				// Horizontal lines first
				if (iterators[0] == 0)
				{
					// Left to right
					tempVertex.x = (iterators[2]) ? -halfGridWidth : halfGridWidth;
					tempVertex.y = 0;
					tempVertex.z = ((iterators[1] - halfGridWidth) * lineDistanceApart);
				}

				// Vertical lines
				else
				{
					// Top to bottom
					tempVertex.x = ((iterators[1] - halfGridWidth) * lineDistanceApart);
					tempVertex.y = 0;
					tempVertex.z = (iterators[2]) ? -halfGridWidth : halfGridWidth;
				}

				// Add lines to drawable vertices and color them
				vertices[vertCount].localPos = tempVertex;
				vertices[vertCount++].color = Colors::White;
			}
		}
	}
}
Grid::Grid(XMVECTOR* position) : GeometricObject(position)
{
	uchar		lineDistanceApart = 2;
	ushort		numberOfGridLines = ushort(numberOfVertices * 0.25f);
	ushort		halfGridWidth = ushort(numberOfGridLines * 0.5f);
	ushort		vertCount;
	XMFLOAT3	tempVertex;

	// Horizontal & Vertical lines
	for (vertCount = 0, iterators[0] = 0; iterators[0] < 2; ++iterators[0])
	{
		// Number of gridlines per direction
		for (iterators[1] = 0; iterators[1] < numberOfGridLines; ++iterators[1])
		{
			// Start and end points
			for (iterators[2] = 0; iterators[2] < 2; ++iterators[2])
			{
				// Horizontal lines first
				if (iterators[0] == 0)
				{
					// Left to right
					tempVertex.x = (iterators[2]) ? -halfGridWidth : halfGridWidth;
					tempVertex.y = 0;
					tempVertex.z = ((iterators[1] - halfGridWidth) * lineDistanceApart);
				}

				// Vertical lines
				else
				{
					// Top to bottom
					tempVertex.x = ((iterators[1] - halfGridWidth) * lineDistanceApart);
					tempVertex.y = 0;
					tempVertex.z = (iterators[2]) ? -halfGridWidth : halfGridWidth;
				}

				// Add lines to drawable vertices and color them
				vertices[vertCount].localPos = tempVertex;
				vertices[vertCount++].color = Colors::White;
			}
		}
	}
}
#pragma endregion

#pragma region Public Interface
void Grid::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices - 1; iterators[0] += 2)
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[iterators[0] + 1].localPos,
								vertices[iterators[0]].color, vertices[iterators[0] + 1].color);
}
#pragma endregion