#pragma region Dependencies
// My Headers	
#include "Pyramid.h"		// Connection to declarations
#include "GlobalApplication.h"
#include "GlobalGeometry.h"
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Pyramid::DrawMe(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfLineIndicesVertices[0]; ++iterators[0])
	{
		lineRenderer.AddNewLine(vertices[lineIndices[iterators[0]][0]].localPos, vertices[lineIndices[iterators[0]][1]].localPos,
								vertices[lineIndices[iterators[0]][0]].color, vertices[lineIndices[iterators[0]][1]].color);
	}
}
#pragma endregion

#pragma region Private
void Pyramid::CreateShape(float scale)
{
	// Create Vertices
	for (iterators[0] = 0; iterators[0] < numberOfLineIndicesVertices[1]; ++iterators[0])
	{
		if (iterators[0] < 4)
		{
			vertices[iterators[0]].localPos.x = (iterators[0] % 4 == 0 || iterators[0] % 4 == 3) ? -scale : scale;
			vertices[iterators[0]].localPos.y = -scale;
			vertices[iterators[0]].localPos.z = (iterators[0] < 2) ? -scale : scale;
		}
		else
		{
			vertices[iterators[0]].localPos.x = 0;
			vertices[iterators[0]].localPos.y = scale;
			vertices[iterators[0]].localPos.z = 0;
		}

		vertices[iterators[0]].color = Colors::Green;
	}

	// Create Indices
	char tempIndices[] =
	{
		4, 1, 0,
		4, 2, 1,
		4, 3, 2,
		4, 0, 3
	};

	// Iterators for tempIndices traversal
	uchar index = 0;

	// Create triangle Indices (backwards L)
	for (iterators[0] = 0; iterators[0] < numberOfLineIndicesVertices[0]; ++iterators[0])
	{
		// Start vert & end vert
		for (iterators[1] = 0; iterators[1] < 2; ++iterators[1])
			lineIndices[iterators[0]][iterators[1]] = tempIndices[index++];

		if (iterators[0] % 2 == 0) --index;
	}
}
#pragma endregion