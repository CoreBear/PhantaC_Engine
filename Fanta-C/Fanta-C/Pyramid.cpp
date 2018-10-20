#pragma region Dependencies
// My Headers	
#include "Pyramid.h"		// Connection to declarations
#include "LineRenderer.h"
#pragma endregion

#pragma region Initialization
Pyramid::Pyramid(float scale, float inMoveSpeed, float inRotationSpeed) : RenderObject(inMoveSpeed, inRotationSpeed)
{
	//// XYZ
	//for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
	//	extents.m128_f32[iterators[0]] = scale;

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[1]; ++iterators[0])
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

	char tempIndices[] =
	{
		0, 1, 2, 3, 0,	// Bottom face
		4, 1, 3, 4, 2	// Connectors
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
Pyramid::Pyramid(XMVECTOR* position, float scale, float inMoveSpeed, float inRotationSpeed) : RenderObject(position, inMoveSpeed, inRotationSpeed)
{
	//// XYZ
	//for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
	//	extents.m128_f32[iterators[0]] = scale;

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[1]; ++iterators[0])
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

	char tempIndices[] =
	{
		0, 1, 2, 3, 0,	// Bottom face
		4, 1, 3, 4, 2	// Connectors
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
Pyramid::Pyramid(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale, float inMoveSpeed, float inRotationSpeed) : RenderObject(position, forward, up, inMoveSpeed, inRotationSpeed)
{
	//// XYZ
	//for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
	//	extents.m128_f32[iterators[0]] = scale;

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[1]; ++iterators[0])
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

	char tempIndices[] =
	{
		0, 1, 2, 3, 0,	// Bottom face
		4, 1, 3, 4, 2	// Connectors
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
#pragma endregion

#pragma region Public Interface
void Pyramid::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0] - 1; ++iterators[0])
	{
		lineRenderer.AddNewLine(vertices[indices[iterators[0]]].localPos, vertices[indices[iterators[0] + 1]].localPos,
			vertices[indices[iterators[0]]].color, vertices[indices[iterators[0] + 1]].color);
	}
}
#pragma endregion