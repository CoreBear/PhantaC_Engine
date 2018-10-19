#ifndef _PLAYER_H
#define _PLAYER_H

#include "Typedefs.h"

class Player
{
	class TransformObject* characterPtr;

public:
	// Initialization
	Player(TransformObject* inCharacter) : characterPtr(inCharacter) { return; }

	// Public Interface
	void ControllerInput(ushort key);
};

#endif