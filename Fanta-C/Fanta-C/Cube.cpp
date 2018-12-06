#pragma region Dependencies
// My Headers
#include "Cube.h"		// Connection to declarations
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Cube::AddMyLinesToRenderer(LineRenderer& lineRenderer)
{
	for (reusableIterator = 0; reusableIterator < numberOfLinesTriIndicesVertices[1]; ++reusableIterator)
	{
		for (secondIterator = 0; secondIterator < numberOfLinesTriIndicesVertices[0]; ++secondIterator)
			lineRenderer.AddNewLine(vertices[triIndices[reusableIterator][secondIterator][0]].localPos, vertices[triIndices[reusableIterator][secondIterator][1]].localPos, color, color);
	}
}
#pragma endregion

#pragma region Private
void Cube::CreateMesh(float inWidth, float inHeight, float inDepth, float inScale)
{
	for (reusableIterator = 0; reusableIterator < numberOfLinesTriIndicesVertices[2]; ++reusableIterator)
	{
		vertices[reusableIterator].localPos.m128_f32[0] = (reusableIterator % 4 == 0 || reusableIterator % 4 == 3) ? -inWidth * inScale : inWidth * inScale;
		vertices[reusableIterator].localPos.m128_f32[1] = (reusableIterator % 4 < 2) ? inHeight * inScale : -inHeight * inScale;
		vertices[reusableIterator].localPos.m128_f32[2] = (reusableIterator < 4) ? -inDepth * inScale : inDepth * inScale;
	}

	char tempIndices[] =
	{
		0, 1, 2, 3,	// Front Face
		1, 5, 6, 2,	// Right Face
		5, 4, 7, 6,	// Back Face
		4, 0, 3, 7	// Right Face
	};

	uchar index = 0;
	uchar iterators[2];

	// Create triple Indices (backwards C)
	for (reusableIterator = 0; reusableIterator < numberOfLinesTriIndicesVertices[1]; ++reusableIterator)
	{
		// Number of lines
		for (iterators[0] = 0; iterators[0] < numberOfLinesTriIndicesVertices[0]; ++iterators[0])
		{
			// Start vert & end vert
			for (secondIterator = 0; secondIterator < 2; ++secondIterator)
				triIndices[reusableIterator][iterators[0]][secondIterator] = tempIndices[index++];

			if (iterators[0] != numberOfLinesTriIndicesVertices[0] - 1) --index;
		}
	}
}
#pragma endregion