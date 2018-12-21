#ifndef _RAY_CAST_H
#define _RAY_CAST_H

// My Headers
#include "GlobalDirectX.h"
#include "SceneObject.h"

class RayCast
{
private:
	// Variables
	static constexpr float	allowableLimit = 0.99f; // Strict for now
	static uchar			objectCheckStartIndex;
	static ushort			iterator;
	static XMVECTOR			checkObjectsMinMax[2];
	static XMVECTOR			checkedObjectDirection;
	static XMVECTOR			rayCastDirection;
	static XMVECTOR			startEnd[2];

public:
	// Public Interface
	static SceneObject* Cast(XMVECTOR* startPosition, XMVECTOR* endPosition);

	// Mutators
	static void UpdateRayCastStartIndex(uchar index);
};

#endif