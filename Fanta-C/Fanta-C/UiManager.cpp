#pragma region Dependencies
// My Headers
#include "UiManager.h"			// Connection to declarations
#pragma endregion

#pragma region Forward Declarations
UiManager* UiManager::uiManagerInstance = nullptr;
#pragma endregion

#pragma region Accessors
UiManager* UiManager::GetInstance()
{
	// If instance has been created, return it
	if (uiManagerInstance) return uiManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		uiManagerInstance = new UiManager;
		return uiManagerInstance;
	}
}
#pragma endregion