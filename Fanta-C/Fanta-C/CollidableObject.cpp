#pragma region Dependencies
// My Headers
#include "CollidableObject.h"		// Connection to declarations
#pragma endregion

#pragma region Private
void CollidableObject::CreateBounds(bool shapeIsFlat, float scale)
{	
	const float flatShapeWidth = 0.05f;

	// Creates cube or square (if flat)
	extents.m128_f32[0] = scale;
	extents.m128_f32[1] = scale;
	extents.m128_f32[2] = (shapeIsFlat) ? flatShapeWidth : scale;
}
#pragma endregion