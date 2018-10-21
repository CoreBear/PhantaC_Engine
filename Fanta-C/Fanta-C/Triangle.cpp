#pragma region Dependencies
// My Headers
#include "Triangle.h"			// Connection to declarations
#include "LineRenderer.h"
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

#pragma region Private
void Triangle::CreateShape(float scale)
{
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
