#ifndef _GLOBAL_MATH_H
#define _GLOBAL_MATH_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

const static float multiplicativeThird = float(1) / 3;
static float		dotProduct;
static float		normValue;
static uchar		mathIterator;
static XMVECTOR*	returnedVector;
class GlobalMath
{
public:
		// Public Interface
	static float AbsoluteValue(float value);
	static float Lerp(float min, float max, float length);
	static void Normalize(XMVECTOR* inVector);
	template<typename Generic> static Generic Square(Generic value);
	static float Vector3DotProduct(XMVECTOR* firstVector, XMVECTOR* secondVector);
	static float Vector4DotProduct(XMVECTOR* firstVector, XMVECTOR* secondVector);
	static XMVECTOR* VectorSubtraction(XMVECTOR* firstVector, XMVECTOR* secondVector);
};

#endif