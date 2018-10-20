#pragma region Dependencies
// My Headers
#include "Player.h"			// Connection to declarations
#pragma endregion

#pragma region Public Interface
void Player::ControllerInput(ushort key)
{
	switch (key)
	{
	case A:
		characterPtr->OnYAxis(-characterPtr->GetRotationSpeed());
		break;												   
	case D:													   
		characterPtr->OnYAxis(characterPtr->GetRotationSpeed());
		break;												   
	case I:													   
		characterPtr->OnXAxis(-characterPtr->GetRotationSpeed());
		break;												   
	case J:													   
		characterPtr->OnZAxis(-characterPtr->GetRotationSpeed());
		break;												   
	case K:													   
		characterPtr->OnXAxis(characterPtr->GetRotationSpeed());
		break;												   
	case L:													   
		characterPtr->OnZAxis(characterPtr->GetRotationSpeed());
		break;
	case S:
		characterPtr->Translate(0, 0, characterPtr->GetMoveSpeed());
		break;
	case W:
		characterPtr->Translate(0, 0, -characterPtr->GetMoveSpeed());
		break;
	case SPACE:
		pooledProjectiles.AllocateNew();
		break;
	}
}
#pragma endregion