#pragma region Dependencies
// My Headers
#include "Sphere.h"		// Connection to declarations
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Sphere::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices - 1; ++iterators[0])
	{
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[iterators[0] + 1].localPos,
			vertices[iterators[0]].color, vertices[iterators[0] + 1].color);
	}
}
#pragma endregion

#pragma region Private
void Sphere::CreateShape(float scale)
{
	const ushort halfNumberOfVertices = numberOfVertices * 0.5f;

	// Horizontal circle
	for (iterators[0] = 0; iterators[0] < halfNumberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = cos(XMConvertToRadians(iterators[0])) * scale;	   // Why does cos(iterators[0]); do something weird?
		vertices[iterators[0]].localPos.y = 0;												   // Why does cos(iterators[0]); do something weird?
		vertices[iterators[0]].localPos.z = sin(XMConvertToRadians(iterators[0])) * scale;
		vertices[iterators[0]].color = Colors::LightCyan;
	}

	// Vertical circle
	for (; iterators[0] < numberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = cos(XMConvertToRadians(iterators[0])) * scale;	   // Why does cos(iterators[0]); do something weird?
		vertices[iterators[0]].localPos.y = sin(XMConvertToRadians(iterators[0])) * scale;	   // Why does cos(iterators[0]); do something weird?
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::LightCyan;
	}
}
#pragma endregion