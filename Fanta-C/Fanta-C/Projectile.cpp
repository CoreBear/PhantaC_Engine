#pragma region Dependencies
// My Headers	
#include "Projectile.h"			// Connection to headers
#include "LineRenderer.h"
#pragma endregion

#pragma region Initialization
Projectile::Projectile() : RenderableObject(1, 0)
{
	// Start and end positions
	for (iterators[0] = 0; iterators[0] < 2; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = 0;
		vertices[iterators[0]].localPos.y = 0;
		vertices[iterators[0]].localPos.z = (iterators[0] == 0) ? -1 : 1;
		vertices[iterators[0]].color = Colors::Red;
	}
}
#pragma endregion