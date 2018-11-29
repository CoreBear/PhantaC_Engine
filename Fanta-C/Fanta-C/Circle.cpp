#pragma region Dependencies
// My Headers
#include "Circle.h"		// Connection to declarations

#include "GlobalIterators.h"
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Circle::AddMyLinesToRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices - 1; ++iterators[0])
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[iterators[0] + 1].localPos, color, color);
}
#pragma endregion

#pragma region Private
void Circle::CreateMesh(float inWidth, float inHeight, float inDepth, float inScale)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (inWidth == 0) ? 0 : cos(XMConvertToRadians(iterators[0])) * inWidth * inScale;
		vertices[iterators[0]].localPos.y = sin(XMConvertToRadians(iterators[0])) * inHeight * inScale;
		vertices[iterators[0]].localPos.z = (inDepth == 0) ? 0 : cos(XMConvertToRadians(iterators[0])) * inWidth * inScale;
	}
}
#pragma endregion