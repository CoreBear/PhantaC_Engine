#pragma region Dependencies
// My Headers	
#include "Pyramid.h"		// Connection to declarations
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Pyramid::AddMyLinesToRenderer(LineRenderer& lineRenderer)
{
	for (reusableIterator = 0; reusableIterator < numberOfLineIndicesVertices[0]; ++reusableIterator)
		lineRenderer.AddNewLine(vertices[lineIndices[reusableIterator][0]].localPos, vertices[lineIndices[reusableIterator][1]].localPos, color, color);
}
#pragma endregion

#pragma region Private
void Pyramid::CreateMesh(float inWidth, float inHeight, float inDepth, float inScale)
{
	// Create Vertices
	for (reusableIterator = 0; reusableIterator < numberOfLineIndicesVertices[1]; ++reusableIterator)
	{
		if (reusableIterator < 4)
		{
			vertices[reusableIterator].localPos.x = (reusableIterator % 4 == 0 || reusableIterator % 4 == 3) ? -inWidth * inScale : inWidth * inScale;
			vertices[reusableIterator].localPos.y = -inHeight * inScale;
			vertices[reusableIterator].localPos.z = (reusableIterator < 2) ? -inDepth * inScale : inDepth * inScale;
		}
		else
		{
			vertices[reusableIterator].localPos.x = 0;
			vertices[reusableIterator].localPos.y = inHeight * inScale;
			vertices[reusableIterator].localPos.z = 0;
		}

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
	uchar iterator;

	// Create triangle Indices (backwards L)
	for (reusableIterator = 0; reusableIterator < numberOfLineIndicesVertices[0]; ++reusableIterator)
	{
		// Start vert & end vert
		for (iterator = 0; iterator < 2; ++iterator)
			lineIndices[reusableIterator][iterator] = tempIndices[index++];

		if (reusableIterator % 2 == 0) --index;
	}
}
#pragma endregion