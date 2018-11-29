#pragma region Dependencies
// My Headers
#include "Quad.h"		// Connection to declarations
#include "GlobalIterators.h"
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Quad::AddMyLinesToRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[(iterators[0] + 1) % numberOfVertices].localPos, color, color);
}
#pragma endregion

#pragma region Private
void Quad::CreateMesh(float inWidth, float inHeight, float inDepth, float inScale)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		// X
		if (inWidth == 0)
			vertices[iterators[0]].localPos.x = 0;
		else
			vertices[iterators[0]].localPos.x = (iterators[0] % numberOfVertices == 0 || iterators[0] % numberOfVertices == numberOfVertices - 1) ? -inWidth * inScale : inWidth * inScale;
		
		// Y
		vertices[iterators[0]].localPos.y = (iterators[0] % numberOfVertices < numberOfVertices * 0.5f) ? inHeight * inScale : -inHeight * inScale;
		
		// Z
		if (inDepth == 0)
			vertices[iterators[0]].localPos.z = 0;
		else
			vertices[iterators[0]].localPos.z = (iterators[0] % numberOfVertices == 0 || iterators[0] % numberOfVertices == numberOfVertices - 1) ? -inDepth * inScale : inDepth * inScale;
	}
}
#pragma endregion