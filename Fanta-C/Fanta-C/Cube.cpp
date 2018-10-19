#include "Cube.h"

Cube::Cube(float scale)
{
	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[1]; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % 4 == 0 || iterators[0] % 4 == 3) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % 4 < 2) ? scale : -scale;
		vertices[iterators[0]].localPos.z = (iterators[0] < 4) ? -scale : scale;
		vertices[iterators[0]].color = Colors::Red;
	}

	char tempIndices[] =
	{
		0, 1, 2, 3, 0,	// Front face
		4, 5, 6, 7,	4,	// Back face
		0, 4, 1, 5,		// Top connectors
		2, 6, 3, 7		// Bottom connectors
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
Cube::Cube(XMVECTOR* position, float scale) : GeometricObject(position)
{
	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[1]; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % 4 == 0 || iterators[0] % 4 == 3) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % 4 < 2) ? scale : -scale;
		vertices[iterators[0]].localPos.z = (iterators[0] < 4) ? -scale : scale;
		vertices[iterators[0]].color = Colors::Red;
	}

	char tempIndices[] =
	{
		0, 1, 2, 3, 0,	// Front face
		4, 5, 6, 7,	4,	// Back face
		0, 4, 1, 5,		// Top connectors
		2, 6, 3, 7		// Bottom connectors
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
Cube::Cube(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale, float inMoveSpeed, float inRotationSpeed) : GeometricObject(position, forward, up, inMoveSpeed, inRotationSpeed)
{
	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[1]; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % 4 == 0 || iterators[0] % 4 == 3) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % 4 < 2) ? scale : -scale;
		vertices[iterators[0]].localPos.z = (iterators[0] < 4) ? -scale : scale;
		vertices[iterators[0]].color = Colors::Red;
	}

	char tempIndices[] =
	{
		0, 1, 2, 3, 0,	// Front face
		4, 5, 6, 7,	4,	// Back face
		0, 4, 1, 5,		// Top connectors
		2, 6, 3, 7		// Bottom connectors
	};

	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0]; ++iterators[0])
		indices[iterators[0]] = tempIndices[iterators[0]];
}
void Cube::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfIndicesVertices[0] - 1; ++iterators[0])
	{
		if (iterators[0] < 9)
		{
			if (iterators[0] != 4)
				lineRenderer.AddNewLine(vertices[indices[iterators[0]]].localPos, vertices[indices[iterators[0] + 1]].localPos,
										vertices[indices[iterators[0]]].color, vertices[indices[iterators[0] + 1]].color);
		}
		else
		{
			if (iterators[0] % 2 == 0)
			{
				lineRenderer.AddNewLine(vertices[indices[iterators[0]]].localPos, vertices[indices[iterators[0] + 1]].localPos,
					vertices[indices[iterators[0]]].color, vertices[indices[iterators[0] + 1]].color);
			}
		}
	}
}