#pragma region Dependencies
// My Headers
#include "Circle.h"		// Connection to declarations
#include "GlobalApplication.h"
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Circle::AddMyLinesToRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices - 1; ++iterators[0])
	{
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[iterators[0] + 1].localPos,
			vertices[iterators[0]].color, vertices[iterators[0] + 1].color);
	}
}
#pragma endregion

#pragma region Private
void Circle::CreateMesh()
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = cos(XMConvertToRadians(iterators[0])) * scale;	   // Why does cos(iterators[0]); do something weird?
		vertices[iterators[0]].localPos.y = sin(XMConvertToRadians(iterators[0])) * scale;	   // Why does cos(iterators[0]); do something weird?
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::LightCyan;
	}
}
#pragma endregion