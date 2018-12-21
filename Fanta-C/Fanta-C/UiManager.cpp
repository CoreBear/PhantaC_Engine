#pragma region Dependencies
// My Headers
#include "UiManager.h"			// Connection to declarations

#include "Renderer.h"
#pragma endregion

#pragma region Forward Declarations
UiManager* UiManager::uiManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
UiManager* UiManager::GetInstance(Renderer* renderer)
{
	// If instance has been created, return it
	if (uiManagerInstance) return uiManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		uiManagerInstance = new UiManager(renderer);
		return uiManagerInstance;
	}
}
#pragma endregion

#pragma region Update
void UiManager::Update()
{
	renderPtr->DrawUI();
}
#pragma endregion