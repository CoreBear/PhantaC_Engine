#ifndef _PLAYER_H
#define _PLAYER_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalInput.h"
#include "MoveableObject.h"
#include "Pool.h"
#include "Projectile.h"
#include "Typedefs.h"

class Player
{
	MoveableObject*			characterPtr;
	Pool<Projectile, 20>	pooledProjectiles;
	XMMATRIX*				myWorldMatrixPtr;

public:
	// Initialization
	Player(MoveableObject* inCharacter, XMMATRIX* inMyWorldMatrixPtr) : characterPtr(inCharacter), myWorldMatrixPtr(inMyWorldMatrixPtr) { return; }

	// Public Interface
	void ControllerInput(ushort key);
};

#endif