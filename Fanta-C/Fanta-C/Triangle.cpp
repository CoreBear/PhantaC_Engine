#pragma region Dependencies
// My Headers
#include "Triangle.h"			// Connection to declarations
#include "GlobalIterators.h"
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Triangle::AddMyLinesToRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[(iterators[0] + 1) % numberOfVertices].localPos, color, color);
}
#pragma endregion

#pragma region Private
void Triangle::CreateMesh(float inWidth, float inHeight, float inDepth, float inScale)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		// X
		if (inWidth == 0)
			vertices[iterators[0]].localPos.x = 0;
		else
		{
			switch (iterators[0])
			{
			case 0:
				vertices[iterators[0]].localPos.x = -inWidth * inScale;
				break;
			case 1:
				vertices[iterators[0]].localPos.x = 0;
				break;
			case 2:
				vertices[iterators[0]].localPos.x = inWidth * inScale;
				break;
			}
		}

		// Y
		vertices[iterators[0]].localPos.y = (iterators[0] != 1) ? -inHeight * inScale : inHeight * inScale;

		// Z
		if (inDepth == 0)
			vertices[iterators[0]].localPos.z = 0;
		else
		{
			switch (iterators[0])
			{
			case 0:
				vertices[iterators[0]].localPos.z = -inDepth * inScale;
				break;
			case 1:
				vertices[iterators[0]].localPos.z = 0;
				break;
			case 2:
				vertices[iterators[0]].localPos.z = inDepth * inScale;
				break;
			}
		}
	}
}
#pragma endregion