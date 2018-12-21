#ifndef _SPAWNER_H
#define _SPAWNER_h

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

class Spawner
{
	// Variables
	static ushort iterator;

public:
	// Public Interface
	static class SceneObject* SpawnBulletTrail(XMVECTOR* startPosition, XMVECTOR* endPosition);
};

#endif