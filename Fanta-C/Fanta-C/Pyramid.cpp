#include "Pyramid.h"

Pyramid::Pyramid(float scale)
{
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
Pyramid::Pyramid(float x, float y, float z, float scale) : GeometricObject(x, y, z)
{
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