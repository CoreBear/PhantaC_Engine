#ifndef _RAY_CAST_H
#define _RAY_CAST_H

// My Headers
#include "GlobalDirectX.h"

struct RayCast
{
private:
	// Variables
	XMVECTOR startEnd[2];

	// Private Functionality
	bool Hit();

public:
	// Public Interface
	bool Cast(XMVECTOR* startPosition, XMVECTOR* endPosition);
};

#endif