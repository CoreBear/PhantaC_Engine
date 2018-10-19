#pragma region Dependencies
// My Headers	
#include "Pyramid.h"		// Connection to declarations
#pragma endregion

#pragma region Initialization
Pyramid::Pyramid(float scale) : centroid(XMVectorSet(0, 0, 0, 1))
{
	// XYZ
	for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
		extents.m128_f32[iterators[0]] = scale;

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
		0, 1, 2, 3, 0,			// Bottom face
		4, 0, 4, 1, 4, 2, 4, 3	// Connectors
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
Pyramid::Pyramid(XMVECTOR* position, float scale) : centroid(*position), GeometricObject(position)
{
	// XYZ
	for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
		extents.m128_f32[iterators[0]] = scale;

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
		0, 1, 2, 3, 0,			// Bottom face
		4, 0, 4, 1, 4, 2, 4, 3	// Connectors
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
Pyramid::Pyramid(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale, float inMoveSpeed, float inRotationSpeed) : centroid(*position), GeometricObject(position, forward, up, inMoveSpeed, inRotationSpeed)
{
	// XYZ
	for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
		extents.m128_f32[iterators[0]] = scale;

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
		0, 1, 2, 3, 0,			// Bottom face
		4, 0, 4, 1, 4, 2, 4, 3	// Connectors
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
#pragma endregion

#pragma region Public Interface
void Pyramid::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
	{
		if (iterators[0] < 4)
		{
				lineRenderer.AddNewLine(vertices[indices[iterators[0]]].localPos, vertices[indices[(iterators[0] + 1) % 4]].localPos,
					vertices[indices[iterators[0]]].color, vertices[indices[(iterators[0] + 1) % 4]].color);
		}
		else
		{
			if (iterators[0] % 2 != 0)
			{
				lineRenderer.AddNewLine(vertices[indices[iterators[0]]].localPos, vertices[indices[iterators[0] + 1]].localPos,
					vertices[indices[iterators[0]]].color, vertices[indices[iterators[0] + 1]].color);
			}
		}
	}
}
#pragma endregion