#pragma region Dependencies
// My Headers
#include "Player.h"			// Connection to declarations
#include "GlobalInput.h"
#pragma endregion

#pragma region Public Interface
void Player::ControllerInput(ushort key, float deltaTime)
{
	// For camera
	switch (key)
	{
	case A:
		physicalBodyPtr->RotateOnWorldYAxis(-physicalBodyPtr->GetRotationSpeed() * deltaTime);
		break;
	case D:
		physicalBodyPtr->RotateOnWorldYAxis(physicalBodyPtr->GetRotationSpeed() * deltaTime);
		break;
	case I:
		physicalBodyPtr->RotateOnWorldXAxis(-physicalBodyPtr->GetRotationSpeed() * deltaTime);
		break;
	case J:
		physicalBodyPtr->RotateOnWorldZAxis(-physicalBodyPtr->GetRotationSpeed() * deltaTime);
		break;
	case K:
		physicalBodyPtr->RotateOnWorldXAxis(physicalBodyPtr->GetRotationSpeed() * deltaTime);
		break;
	case L:
		physicalBodyPtr->RotateOnWorldZAxis(physicalBodyPtr->GetRotationSpeed() * deltaTime);
		break;
	case S:
		physicalBodyPtr->Translate(0, 0, physicalBodyPtr->GetMoveSpeed() * deltaTime);
		break;
	case W:
		physicalBodyPtr->Translate(0, 0, -physicalBodyPtr->GetMoveSpeed() * deltaTime);
		break;
	case SPACE:
		break;
	}
}
#pragma endregion

#pragma region Use this code if the player is a world object other than the camera
// For world objects
/*switch (key)
{
case A:
physicalBodyPtr->RotateOnYAxis(physicalBodyPtr->GetRotationSpeed());
break;
case D:
physicalBodyPtr->RotateOnYAxis(-physicalBodyPtr->GetRotationSpeed());
break;
case I:
physicalBodyPtr->RotateOnXAxis(physicalBodyPtr->GetRotationSpeed());
break;
case J:
physicalBodyPtr->RotateOnZAxis(physicalBodyPtr->GetRotationSpeed());
break;
case K:
physicalBodyPtr->RotateOnXAxis(-physicalBodyPtr->GetRotationSpeed());
break;
case L:
physicalBodyPtr->RotateOnZAxis(-physicalBodyPtr->GetRotationSpeed());
break;
case S:
physicalBodyPtr->WorldTranslate(2, -physicalBodyPtr->GetMoveSpeed());
break;
case W:
physicalBodyPtr->WorldTranslate(2, physicalBodyPtr->GetMoveSpeed());
break;
case SPACE:
break;
}*/
#pragma endregion