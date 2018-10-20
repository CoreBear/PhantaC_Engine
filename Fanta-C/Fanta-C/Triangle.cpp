#pragma region Dependencies
// My Headers
#include "Triangle.h"			// Connection to declarations
#include "LineRenderer.h"
#pragma endregion

#pragma region Initialization
Triangle::Triangle(float scale)
{
	// XYZ (Make sure triangle is flat by making z = 0)
	for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
		extents.m128_f32[iterators[0]] = (iterators[0] != 2) ? scale : 0;

	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		switch (iterators[0])
		{
		case 0:
			vertices[iterators[0]].localPos.x = -scale;
			break;
		case 1:
			vertices[iterators[0]].localPos.x = 0;
			break;
		case 2:
			vertices[iterators[0]].localPos.x = scale;
			break;
		}
		vertices[iterators[0]].localPos.y = (iterators[0] != 1) ? -scale : scale;
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::Blue;
	}
}
Triangle::Triangle(XMVECTOR* position, float scale) : RenderObject(position)
{
	// XYZ (Make sure triangle is flat by making z = 0
	for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
		extents.m128_f32[iterators[0]] = (iterators[0] != 2) ? scale : 0;

	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		switch (iterators[0])
		{
		case 0:
			vertices[iterators[0]].localPos.x = -scale;
			break;
		case 1:
			vertices[iterators[0]].localPos.x = 0;
			break;
		case 2:
			vertices[iterators[0]].localPos.x = scale;
			break;
		}
		vertices[iterators[0]].localPos.y = (iterators[0] != 1) ? -scale : scale;
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::Blue;
	}
}
Triangle::Triangle(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale) : RenderObject(position, forward, up)
{
	// XYZ (Make sure triangle is flat by making z = 0
	for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
		extents.m128_f32[iterators[0]] = (iterators[0] != 2) ? scale : 0;

	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		switch (iterators[0])
		{
		case 0:
			vertices[iterators[0]].localPos.x = -scale;
			break;
		case 1:
			vertices[iterators[0]].localPos.x = 0;
			break;
		case 2:
			vertices[iterators[0]].localPos.x = scale;
			break;
		}
		vertices[iterators[0]].localPos.y = (iterators[0] != 1) ? -scale : scale;
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::Blue;
	}
}
#pragma endregion

#pragma region Public Interface
void Triangle::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[(iterators[0] + 1) % numberOfVertices].localPos,
			vertices[iterators[0]].color, vertices[(iterators[0] + 1) % numberOfVertices].color);
	}
}
#pragma endregion