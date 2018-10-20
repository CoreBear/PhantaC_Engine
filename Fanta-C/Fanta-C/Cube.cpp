#pragma region Dependencies
// My Headers
#include "Cube.h"		// Connection to declarations
#include "LineRenderer.h"
#pragma endregion

#pragma region Initialization
Cube::Cube(float scale, float inMoveSpeed, float inRotationSpeed) : RenderObject(inMoveSpeed, inRotationSpeed)
{
	//// XYZ
	//for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
	//	extents.m128_f32[iterators[0]] = scale;

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[1]; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % 4 == 0 || iterators[0] % 4 == 3) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % 4 < 2) ? scale : -scale;
		vertices[iterators[0]].localPos.z = (iterators[0] < 4) ? -scale : scale;
		vertices[iterators[0]].color = Colors::Red;
	}

	char tempIndices[] =
	{
		3, 0, 1, 3,		3, 1, 2, 3,	// Front Face
		2, 1, 5, 2,		2, 5, 6, 2, // Right Face
		6, 5, 4, 6,		6, 4, 7, 6, // Back Face
		7, 4, 0, 7,		7, 0, 3, 7	// Right Face
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
Cube::Cube(XMVECTOR* position, float scale, float inMoveSpeed, float inRotationSpeed) : RenderObject(position, inMoveSpeed, inRotationSpeed)
{
	//// XYZ
	//for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
	//	extents.m128_f32[iterators[0]] = scale;

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[1]; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % 4 == 0 || iterators[0] % 4 == 3) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % 4 < 2) ? scale : -scale;
		vertices[iterators[0]].localPos.z = (iterators[0] < 4) ? -scale : scale;
		vertices[iterators[0]].color = Colors::Red;
	}

	char tempIndices[] =
	{
		3, 0, 1, 3,		3, 1, 2, 3,	// Front Face
		2, 1, 5, 2,		2, 5, 6, 2, // Right Face
		6, 5, 4, 6,		6, 4, 7, 6, // Back Face
		7, 4, 0, 7,		7, 0, 3, 7	// Right Face
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
Cube::Cube(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale, float inMoveSpeed, float inRotationSpeed) : RenderObject(position, forward, up, inMoveSpeed, inRotationSpeed)
{
	//// XYZ
	//for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
	//	extents.m128_f32[iterators[0]] = scale;

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[1]; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % 4 == 0 || iterators[0] % 4 == 3) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % 4 < 2) ? scale : -scale;
		vertices[iterators[0]].localPos.z = (iterators[0] < 4) ? -scale : scale;
		vertices[iterators[0]].color = Colors::Red;
	}

	char tempIndices[] =
	{
		3, 0, 1, 3,		3, 1, 2, 3,	// Front Face
		2, 1, 5, 2,		2, 5, 6, 2, // Right Face
		6, 5, 4, 6,		6, 4, 7, 6, // Back Face
		7, 4, 0, 7,		7, 0, 3, 7	// Right Face
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
#pragma endregion

#pragma region Public Interface
void Cube::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0] - 1; ++iterators[0])
	{
		lineRenderer.AddNewLine(vertices[indices[iterators[0]]].localPos, vertices[indices[iterators[0] + 1]].localPos,
			vertices[indices[iterators[0]]].color, vertices[indices[iterators[0] + 1]].color);
	}
}
#pragma endregion