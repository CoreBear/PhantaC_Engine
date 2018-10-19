#pragma region Dependencies
// My Headers
#include "Player.h"			// Connection to declarations
#include "InputGlobals.h"
#include "TransformObject.h"
#pragma endregion

#pragma region Public Interface
void Player::ControllerInput(ushort key)
{
	switch (key)
	{
	case A:
		characterPtr->Translate(-1, 0, 0);
		break;
	case D:
		characterPtr->Translate(1, 0, 0);
		break;
	case I:
		break;
	case J:
		break;
	case K:
		break;
	case L:
		break;
	case S:
		break;
	case W:
		break;
	case SPACE:
		break;
	}
}
#pragma endregion