#ifndef _INPUT_CONTROLLER_H
#define _INPUT_CONTROLLER_H

#include "InputGlobals.h"
#include "Typedefs.h"
#include "Camera.h"
#include "Player.h"

class InputController
{
	bool		keysCurrentlyPressed[9] = { false };
	Player*		playerPtr;									

	//// Black Box
	//// Down
	//void KeyADown() { playerPtr->ControllerInput(); }
	//void KeyDDown() { playerPtr->ControllerInput(); }
	//void KeyIDown() { playerPtr->ControllerInput(); }
	//void KeyJDown() { playerPtr->ControllerInput(); }
	//void KeyKDown() { playerPtr->ControllerInput(); }
	//void KeyLDown() { playerPtr->ControllerInput(); }
	//void KeySDown() { playerPtr->ControllerInput(); }
	//void KeyWDown() { playerPtr->ControllerInput(); }
	//void KeySpaceDown() { playerPtr->ControllerInput(); }
	//// Up
	//void KeyAUp() { playerPtr->ControllerInput(); }
	//void KeyDUp() { playerPtr->ControllerInput(); }
	//void KeyIUp() { playerPtr->ControllerInput(); }
	//void KeyJUp() { playerPtr->ControllerInput(); }
	//void KeyKUp() { playerPtr->ControllerInput(); }
	//void KeyLUp() { playerPtr->ControllerInput(); }
	//void KeySUp() { playerPtr->ControllerInput(); }
	//void KeyWUp() { playerPtr->ControllerInput(); }
	//void KeySpaceUp() { playerPtr->ControllerInput(); }

public:	
	// Update
	void Update();

	// Public Interface
	void KeyPressed(ushort keyPressed);
	void KeyReleased(ushort keyReleased);
	void MouseButtonPressed(ushort buttonPressed);
	void MouseButtonRelease(ushort buttonReleased);
	void MouseMovement(ushort xPosition, ushort yPosition);
};

#endif