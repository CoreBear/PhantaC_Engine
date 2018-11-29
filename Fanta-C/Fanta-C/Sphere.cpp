#pragma region Dependencies
// My Headers
#include "Sphere.h"		// Connection to declarations
#include "GlobalIterators.h"
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Sphere::AddMyLinesToRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices - 1; ++iterators[0])
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[iterators[0] + 1].localPos, color, color);
}
#pragma endregion

#pragma region Private
void Sphere::CreateMesh(float inWidth, float inHeight, float inDepth, float inScale)
{
	const ushort halfNumberOfVertices = ushort(numberOfVertices * 0.5f);

	// Horizontal circle
	for (iterators[0] = 0; iterators[0] < halfNumberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = cos(XMConvertToRadians(iterators[0])) * inWidth * inScale;
		vertices[iterators[0]].localPos.y = 0;												   
		vertices[iterators[0]].localPos.z = sin(XMConvertToRadians(iterators[0])) * inDepth * inScale;
	}

	// Vertical circle
	for (; iterators[0] < numberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = cos(XMConvertToRadians(iterators[0])) * inWidth * inScale;
		vertices[iterators[0]].localPos.y = sin(XMConvertToRadians(iterators[0])) * inHeight * inScale;
		vertices[iterators[0]].localPos.z = 0;
	}
}
#pragma endregion