#pragma region Dependencies
// My Headers
#include "Cube.h"		// Connection to declarations
#include "GlobalApplication.h"
#include "GlobalGeometry.h"
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Cube::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfLinesTriIndicesVertices[1]; ++iterators[0])
	{
		for (iterators[1] = 0; iterators[1] < numberOfLinesTriIndicesVertices[0]; ++iterators[1])
		{
			lineRenderer.AddNewLine(vertices[triIndices[iterators[0]][iterators[1]][0]].localPos, vertices[triIndices[iterators[0]][iterators[1]][1]].localPos,
									vertices[triIndices[iterators[0]][iterators[1]][0]].color, vertices[triIndices[iterators[0]][iterators[1]][1]].color);
		}
	}
}
#pragma endregion

#pragma region Private
void Cube::CreateShape(float scale)
{

	for (iterators[0] = 0; iterators[0] < numberOfLinesTriIndicesVertices[2]; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % 4 == 0 || iterators[0] % 4 == 3) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % 4 < 2) ? scale : -scale;
		vertices[iterators[0]].localPos.z = (iterators[0] < 4) ? -scale : scale;
		vertices[iterators[0]].color = Colors::Red;
	}

	char tempIndices[] =
	{
		0, 1, 2, 3,	// Front Face
		1, 5, 6, 2,	// Right Face
		5, 4, 7, 6,	// Back Face
		4, 0, 3, 7	// Right Face
	};

	uchar index = 0;

	// Create triple Indices (backwards C)
	for (iterators[0] = 0; iterators[0] < numberOfLinesTriIndicesVertices[1]; ++iterators[0]) 
	{
		// Number of lines
		for (iterators[1] = 0; iterators[1] < numberOfLinesTriIndicesVertices[0]; ++iterators[1])
		{
			// Start vert & end vert
			for (iterators[2] = 0; iterators[2] < 2; ++iterators[2])
				triIndices[iterators[0]][iterators[1]][iterators[2]] = tempIndices[index++];

			if (iterators[1] != numberOfLinesTriIndicesVertices[0] - 1) --index;
		}
	}
}
#pragma endregion