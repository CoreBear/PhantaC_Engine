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
		transformPtr->RotateOnWorldYAxis(-transformPtr->GetRotationSpeed() * deltaTime);
		break;
	case D:
		transformPtr->RotateOnWorldYAxis(transformPtr->GetRotationSpeed() * deltaTime);
		break;
	case I:
		transformPtr->RotateOnWorldXAxis(-transformPtr->GetRotationSpeed() * deltaTime);
		break;
	case J:
		transformPtr->RotateOnWorldZAxis(-transformPtr->GetRotationSpeed() * deltaTime);
		break;
	case K:
		transformPtr->RotateOnWorldXAxis(transformPtr->GetRotationSpeed() * deltaTime);
		break;
	case L:
		transformPtr->RotateOnWorldZAxis(transformPtr->GetRotationSpeed() * deltaTime);
		break;
	case S:
		transformPtr->Translate(0, 0, transformPtr->GetMoveSpeed() * deltaTime);
		break;
	case W:
		transformPtr->Translate(0, 0, -transformPtr->GetMoveSpeed() * deltaTime);
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
transformPtr->RotateOnYAxis(transformPtr->GetRotationSpeed());
break;
case D:
transformPtr->RotateOnYAxis(-transformPtr->GetRotationSpeed());
break;
case I:
transformPtr->RotateOnXAxis(transformPtr->GetRotationSpeed());
break;
case J:
transformPtr->RotateOnZAxis(transformPtr->GetRotationSpeed());
break;
case K:
transformPtr->RotateOnXAxis(-transformPtr->GetRotationSpeed());
break;
case L:
transformPtr->RotateOnZAxis(-transformPtr->GetRotationSpeed());
break;
case S:
transformPtr->WorldTranslate(2, -transformPtr->GetMoveSpeed());
break;
case W:
transformPtr->WorldTranslate(2, transformPtr->GetMoveSpeed());
break;
case SPACE:
break;
}*/
#pragma endregion