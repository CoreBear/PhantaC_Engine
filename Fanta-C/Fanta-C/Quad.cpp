#include "Quad.h"

Quad::Quad(float scale)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % numberOfVertices == 0 || iterators[0] % numberOfVertices == numberOfVertices - 1) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % numberOfVertices < numberOfVertices * 0.5f) ? scale : -scale;
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::DarkOrange;
	}
}
Quad::Quad(XMVECTOR* position, float scale) : GeometricObject(position)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % numberOfVertices == 0 || iterators[0] % numberOfVertices == numberOfVertices - 1) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % numberOfVertices < numberOfVertices * 0.5f) ? scale : -scale;
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::DarkOrange;
	}
}
Quad::Quad(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale, float inMoveSpeed, float inRotationSpeed) : GeometricObject(position, forward, up, inMoveSpeed, inRotationSpeed)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % numberOfVertices == 0 || iterators[0] % numberOfVertices == numberOfVertices - 1) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % numberOfVertices < numberOfVertices * 0.5f) ? scale : -scale;
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::DarkOrange;
	}
}
void Quad::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[(iterators[0] + 1) % numberOfVertices].localPos,
			vertices[iterators[0]].color, vertices[(iterators[0] + 1) % numberOfVertices].color);
	}
}