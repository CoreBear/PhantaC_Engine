#ifndef _GLOBAL_MATH_H
#define _GLOBAL_MATH_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

static float dotProduct;
static uchar mathIterator;

class GlobalMath
{
public:
	static float Vector3DotProduct(XMVECTOR& firstVector, XMVECTOR& secondVector);
	static float Vector4DotProduct(XMVECTOR& firstVector, XMVECTOR& secondVector);
};

#endif