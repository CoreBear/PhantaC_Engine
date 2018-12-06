#pragma region Dependencies
// My Headers
#include "Sphere.h"		// Connection to declarations
#include "LineRenderer.h"
#pragma endregion

#pragma region Public Interface
void Sphere::AddMyLinesToRenderer(LineRenderer& lineRenderer)
{
	for (reusableIterator = 0; reusableIterator < numberOfVertices - 1; ++reusableIterator)
		lineRenderer.AddNewLine(vertices[reusableIterator].localPos, vertices[reusableIterator + 1].localPos, color, color);
}
#pragma endregion

#pragma region Private
void Sphere::CreateMesh(float inWidth, float inHeight, float inDepth, float inScale)
{
	const ushort halfNumberOfVertices = ushort(numberOfVertices * 0.5f);

	// Horizontal circle
	for (reusableIterator = 0; reusableIterator < halfNumberOfVertices; ++reusableIterator)
	{
		vertices[reusableIterator].localPos.m128_f32[0] = cos(XMConvertToRadians(reusableIterator)) * inWidth * inScale;
		vertices[reusableIterator].localPos.m128_f32[1] = 0;
		vertices[reusableIterator].localPos.m128_f32[2] = sin(XMConvertToRadians(reusableIterator)) * inDepth * inScale;
	}

	// Vertical circle
	for (; reusableIterator < numberOfVertices; ++reusableIterator)
	{
		vertices[reusableIterator].localPos.m128_f32[0] = cos(XMConvertToRadians(reusableIterator)) * inWidth * inScale;
		vertices[reusableIterator].localPos.m128_f32[1] = sin(XMConvertToRadians(reusableIterator)) * inHeight * inScale;
		vertices[reusableIterator].localPos.m128_f32[2] = 0;
	}
}
#pragma endregion