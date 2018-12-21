#pragma region Dependencies
// My Headers
#include "Reticle.h"			// Connection to declarations

#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Reticle::AddMyLinesToRenderer(LineRenderer* lineRenderer)
{
	lineRenderer->AddNewLine(vertices[0].localPos, vertices[1].localPos, color, color);
	lineRenderer->AddNewLine(vertices[1].localPos, vertices[2].localPos, color, color);
	lineRenderer->AddNewLine(vertices[2].localPos, vertices[0].localPos, color, color);
}
#pragma endregion

#pragma region Private
void Reticle::CreateMesh(float inHeight, float inWidth, float inScale)
{
	XMVECTOR tempVertex;

	// Start and end points
	for (reusableIterator = 0; reusableIterator < numberOfVertices; ++reusableIterator)
	{
		switch (reusableIterator)
		{
		// Top Point
		case 0:
			tempVertex.m128_f32[0] = 0;
			tempVertex.m128_f32[1] = inHeight * inScale;
			tempVertex.m128_f32[2] = 0;
			break;
		// Left Point
		case 1:
			tempVertex.m128_f32[0] = -inWidth * inScale;
			tempVertex.m128_f32[1] = -inHeight * inScale;
			tempVertex.m128_f32[2] = 0;
			break;
		// Right Point
		case 2:
			tempVertex.m128_f32[0] = inWidth * inScale;
			tempVertex.m128_f32[1] = -inHeight * inScale;
			tempVertex.m128_f32[2] = 0;
			break;
		}

		// Add lines to drawable vertices and color them
		vertices[reusableIterator].localPos = tempVertex;
	}
}
#pragma endregion