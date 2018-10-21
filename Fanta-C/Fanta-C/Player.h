#ifndef _PLAYER_H
#define _PLAYER_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalInput.h"
#include "ObjectTransform.h"
#include "Typedefs.h"

class Player
{
	ObjectTransform*		characterPtr;
	XMMATRIX*				myWorldMatrixPtr;

public:
	// Initialization
	Player(ObjectTransform* inCharacter, XMMATRIX* inMyWorldMatrixPtr) : characterPtr(inCharacter), myWorldMatrixPtr(inMyWorldMatrixPtr) { return; }

	// Public Interface
	void ControllerInput(ushort key);
};

#endif