#ifndef _INPUT_CONTROLLER_H
#define _INPUT_CONTROLLER_H

// My Headers
#include "GlobalInput.h"
#include "GlobalTypedefs.h"

// Forward Declarations
class Player;

class InputManager
{
	bool	keysCurrentlyPressed[9] = { false };
	Player*	playerPtr;									

public:	
	// Update
	void Update(float deltaTime);

	// Public Interface
	void KeyPressed(ushort keyPressed);
	void KeyReleased(ushort keyReleased);
	void MouseButtonPressed(ushort buttonPressed);
	void MouseButtonRelease(ushort buttonReleased);
	void MouseMovement(ushort xPosition, ushort yPosition);

	// Mutators
	void AssignPlayer(Player* inPlayerPtr) { playerPtr = inPlayerPtr; }
};

#endif