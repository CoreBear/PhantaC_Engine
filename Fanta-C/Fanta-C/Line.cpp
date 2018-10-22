#pragma region Dependencies
// My Headers	
#include "Line.h"			// Connection to headers
#include "GlobalApplication.h"
#include "GlobalGeometry.h"
#include "LineRenderer.h"
#pragma endregion

#pragma region Initialization
Line::Line() : CollidableObject(worldOrigin, 1)
{
	// Start and end positions
	for (iterators[0] = 0; iterators[0] < 2; ++iterators[0])
	{
		vertices[iterators[0]].localPos.x = 0;
		vertices[iterators[0]].localPos.y = 0;
		vertices[iterators[0]].localPos.z = (iterators[0] == 0) ? float(-1) : float(1);
		vertices[iterators[0]].color = Colors::Red;
	}
}
#pragma endregion