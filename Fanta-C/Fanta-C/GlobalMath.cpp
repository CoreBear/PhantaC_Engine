#pragma region Dependencies
// My Headers
#include "GlobalMath.h"			// Connection to declarations
#pragma endregion

#pragma region Public Interface
float GlobalMath::AbsoluteValue(float value)
{
	return (value > 0) ? value : -value;
}
float GlobalMath::Lerp(float min, float max, float length)
{
	return ((max - min) * length) + min;
}
void GlobalMath::Normalize(XMVECTOR* inVector)
{
	normValue = 0;

	for (mathIterator = 0; mathIterator < 3; ++mathIterator)
		normValue += inVector->m128_f32[mathIterator] * inVector->m128_f32[mathIterator];

	normValue *= multiplicativeThird;

	for (mathIterator = 0; mathIterator < 3; ++mathIterator)
		inVector->m128_f32[mathIterator] /= normValue;
}
template<typename Generic> Generic GlobalMath::Square(Generic value)
{
	return value * value;
}
float GlobalMath::Vector3DotProduct(XMVECTOR* firstVector, XMVECTOR* secondVector)
{
	dotProduct = 0;

	for (mathIterator = 0; mathIterator < 3; ++mathIterator)
		dotProduct += firstVector->m128_f32[mathIterator] * secondVector->m128_f32[mathIterator];

	return dotProduct;
}
float GlobalMath::Vector4DotProduct(XMVECTOR* firstVector, XMVECTOR* secondVector)
{
	dotProduct = 0;

	for (mathIterator = 0; mathIterator < 4; ++mathIterator)
		dotProduct += firstVector->m128_f32[mathIterator] * secondVector->m128_f32[mathIterator];

	return dotProduct;
}
XMVECTOR* GlobalMath::VectorSubtraction(XMVECTOR* firstVector, XMVECTOR* secondVector)
{
	for (mathIterator = 0; mathIterator < 4; ++mathIterator)
		returnedVector->m128_f32[mathIterator] = firstVector->m128_f32[mathIterator] - secondVector->m128_f32[mathIterator];

	return returnedVector;
}
#pragma endregion