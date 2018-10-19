#pragma region Dependencies
// My Headers	
#include "Projectile.h"			// Connection to headers
#pragma endregion

#pragma region Initialization
Projectile::Projectile() : centroid(XMVectorSet(0, 0, 0, 1)), GeometricObject(0.01f)
{
	// Start position
	vertices[0].localPos.x = 0;
	vertices[0].localPos.y = 0;
	vertices[0].localPos.z = -1;
	vertices[0].color = Colors::Red;

	// End position
	vertices[1].localPos.x = 0;
	vertices[1].localPos.y = 0;
	vertices[1].localPos.z = 1;
	vertices[1].color = Colors::Red;
}
#pragma endregion

#pragma region Update
void Projectile::Update()
{
	Translate(0, 0, 0.01f);
}
#pragma endregion

#pragma region Public Interface
void Projectile::AddMeToLineRenderer(LineRenderer& lineRenderer)
{
	lineRenderer.AddNewLine(vertices[0].localPos, vertices[1].localPos,	vertices[0].color, vertices[1].color);
}
#pragma endregion
