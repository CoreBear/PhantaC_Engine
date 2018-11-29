#pragma region Dependencies
// My Headers
#include "GlobalMath.h"			// Connection to declarations
#pragma endregion

float GlobalMath::Vector3DotProduct(XMVECTOR& firstVector, XMVECTOR& secondVector)
{
	dotProduct = 0;

	for (mathIterator = 0; mathIterator < 3; ++mathIterator)
		dotProduct += firstVector.m128_f32[mathIterator] * secondVector.m128_f32[mathIterator];

	return dotProduct;
}
float GlobalMath::Vector4DotProduct(XMVECTOR& firstVector, XMVECTOR& secondVector)
{
	dotProduct = 0;

	for (mathIterator = 0; mathIterator < 4; ++mathIterator)
		dotProduct += firstVector.m128_f32[mathIterator] * secondVector.m128_f32[mathIterator];

	return dotProduct;
}