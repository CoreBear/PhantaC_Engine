#pragma region Dependencies
// My Headers
#include "Quad.h"		// Connection to declarations
#include "LineRenderer.h"
#pragma endregion

#pragma region Initialization
Quad::Quad(float scale, float inMoveSpeed, float inRotationSpeed) : RenderObject(inMoveSpeed, inRotationSpeed)
{
	//// XYZ (Make sure quad is flat by making z = 0)
	//for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
	//	extents.m128_f32[iterators[0]] = (iterators[0] != 2) ? scale : 0;

	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % numberOfVertices == 0 || iterators[0] % numberOfVertices == numberOfVertices - 1) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % numberOfVertices < numberOfVertices * 0.5f) ? scale : -scale;
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::DarkOrange;
	}
}
Quad::Quad(XMVECTOR* position, float scale, float inMoveSpeed, float inRotationSpeed) : RenderObject(position, inMoveSpeed, inRotationSpeed)
{
	//// XYZ (Make sure quad is flat by making z = 0
	//for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
	//	extents.m128_f32[iterators[0]] = (iterators[0] != 2) ? scale : 0;

	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % numberOfVertices == 0 || iterators[0] % numberOfVertices == numberOfVertices - 1) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % numberOfVertices < numberOfVertices * 0.5f) ? scale : -scale;
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::DarkOrange;
	}
}
Quad::Quad(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float scale, float inMoveSpeed, float inRotationSpeed) : RenderObject(position, forward, up, inMoveSpeed, inRotationSpeed)
{
	//// XYZ (Make sure quad is flat by making z = 0
	//for (iterators[0] = 0; iterators[0] < 3; ++iterators[0])
	//	extents.m128_f32[iterators[0]] = (iterators[0] != 2) ? scale : 0;

	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = (iterators[0] % numberOfVertices == 0 || iterators[0] % numberOfVertices == numberOfVertices - 1) ? -scale : scale;
		vertices[iterators[0]].localPos.y = (iterators[0] % numberOfVertices < numberOfVertices * 0.5f) ? scale : -scale;
		vertices[iterators[0]].localPos.z = 0;
		vertices[iterators[0]].color = Colors::DarkOrange;
	}
}
#pragma endregion

#pragma region Public Interface
void Quad::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	for (iterators[0] = 0; iterators[0] < numberOfVertices; ++iterators[0])
	{
		lineRenderer.AddNewLine(vertices[iterators[0]].localPos, vertices[(iterators[0] + 1) % numberOfVertices].localPos,
			vertices[iterators[0]].color, vertices[(iterators[0] + 1) % numberOfVertices].color);
	}
}
#pragma endregion