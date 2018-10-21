#pragma region Dependencies
// My Headers
#include "Player.h"			// Connection to declarations
#pragma endregion

#pragma region Public Interface
void Player::ControllerInput(ushort key, float deltaTime)
{
	// For world objects
	/*switch (key)
	{
	case A:
		characterPtr->RotateOnYAxis(characterPtr->GetRotationSpeed());
		break;												   
	case D:													   
		characterPtr->RotateOnYAxis(-characterPtr->GetRotationSpeed());
		break;												   
	case I:													   
		characterPtr->RotateOnXAxis(characterPtr->GetRotationSpeed());
		break;												   
	case J:													   
		characterPtr->RotateOnZAxis(characterPtr->GetRotationSpeed());
		break;												   
	case K:													   
		characterPtr->RotateOnXAxis(-characterPtr->GetRotationSpeed());
		break;												   
	case L:													   
		characterPtr->RotateOnZAxis(-characterPtr->GetRotationSpeed());
		break;
	case S:
		characterPtr->WorldTranslate(2, -characterPtr->GetMoveSpeed());
		break;
	case W:
		characterPtr->WorldTranslate(2, characterPtr->GetMoveSpeed());
		break;
	case SPACE:
		break;
	}*/

	// For camera
	switch (key)
	{
	case A:
		characterPtr->RotateOnWorldYAxis(-characterPtr->GetRotationSpeed() * deltaTime);
		break;
	case D:
		characterPtr->RotateOnWorldYAxis(characterPtr->GetRotationSpeed() * deltaTime);
		break;
	case I:
		characterPtr->RotateOnWorldXAxis(-characterPtr->GetRotationSpeed() * deltaTime);
		break;
	case J:
		characterPtr->RotateOnWorldZAxis(-characterPtr->GetRotationSpeed() * deltaTime);
		break;
	case K:
		characterPtr->RotateOnWorldXAxis(characterPtr->GetRotationSpeed() * deltaTime);
		break;
	case L:
		characterPtr->RotateOnWorldZAxis(characterPtr->GetRotationSpeed() * deltaTime);
		break;
	case S:
		characterPtr->Translate(0, 0, characterPtr->GetMoveSpeed() * deltaTime);
		break;
	case W:
		characterPtr->Translate(0, 0, -characterPtr->GetMoveSpeed() * deltaTime);
		break;
	case SPACE:
		break;
	}
}
#pragma endregion