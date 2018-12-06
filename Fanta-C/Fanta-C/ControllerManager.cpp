#pragma region Dependencies
// My Headers
#include "ControllerManager.h"			// Connection to declarations
#pragma endregion

#pragma region Forward Declarations
ControllerManager* ControllerManager::controllerManagerInstance = nullptr;
#pragma endregion

#pragma region Bumpers
bool ControllerManager::LeftBumper()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
		return true;

	else return false;
}
bool ControllerManager::RightBumper()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
		return true;

	else return false;
}
#pragma endregion

#pragma region D-Pad
bool ControllerManager::Down()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
		return true;

	else return false;
}
bool ControllerManager::Left()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
		return true;

	else return false;
}
bool ControllerManager::Right()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
		return true;

	else return false;
}
bool ControllerManager::Up()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
		return true;

	else return false;
}
#pragma endregion

#pragma region Face Buttons
bool ControllerManager::A()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_A)
		return true;

	else return false;
}
bool ControllerManager::B()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_B)
		return true;

	else return false;
}
bool ControllerManager::X()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_X)
		return true;

	else return false;
}
bool ControllerManager::Y()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y)
		return true;

	else return false;
}
#pragma endregion

#pragma region Joy Sticks
#pragma region Left Stick
int ControllerManager::LeftStickX()
{
	//returns a valuse between -3768 and +3768 so be careful! 
	return state.Gamepad.sThumbLX;
}
int ControllerManager::LeftStickY()
{
	//returns a valuse between -3768 and +3768 so be careful! 
	return state.Gamepad.sThumbLY;
}
bool ControllerManager::LeftStickPressed()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB)
		return true;

	else return false;
}
#pragma endregion

#pragma region Right Stick
int ControllerManager::RightStickX()
{
	//returns a valuse between -3768 and +3768 so be careful! 
	return state.Gamepad.sThumbRX;
}
int ControllerManager::RightStickY()
{
	//returns a valuse between -3768 and +3768 so be careful! 
	return state.Gamepad.sThumbRY;
}
bool ControllerManager::RightStickPressed()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB)
		return true;

	else return false;
}
#pragma endregion
#pragma endregion

#pragma region Misc
bool ControllerManager::CheckControllerStatus() 
{
	// Updates controller state and checks to see if a controller is plugged in
	// Must be called every loop
	 
	// Zeros out the states of the controller
	ZeroMemory(&state, sizeof(XINPUT_STATE)); 
					
	// Gets the state of the controller
	dwResult = XInputGetState(0, &state); 
										  
	// Deadzones for the thumbstics
	if ((state.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) && (state.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		state.Gamepad.sThumbLX = 0;
		state.Gamepad.sThumbLY = 0;
	}
	if ((state.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) && (state.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		state.Gamepad.sThumbRX = 0;
		state.Gamepad.sThumbRY = 0;
	}
	
	// If controller is connected or not
	return (dwResult == ERROR_SUCCESS) ? true : false;
}
#pragma endregion

#pragma region Triggers
int ControllerManager::LeftTrigger()
{
	// Returns a value between 0-255
	if (state.Gamepad.bLeftTrigger && state.Gamepad.bLeftTrigger < XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		return state.Gamepad.bLeftTrigger;
	
	return 0;
}
int ControllerManager::RightTrigger()
{
	// Returns a value between 0-255 
	if (state.Gamepad.bRightTrigger && state.Gamepad.bRightTrigger < XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		return state.Gamepad.bRightTrigger;

	return 0;
}
#pragma endregion

#pragma region Utility Buttons
bool ControllerManager::Back()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
		return true;

	else return false;
}
bool ControllerManager::Start()
{
	if (state.Gamepad.wButtons & XINPUT_GAMEPAD_START)
		return true;

	else return false;
}
#pragma endregion

#pragma region Vibrations
void ControllerManager::VibrateOff()
{
	// Turns off the vibrations 
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));	// Clear out the chunk of data to be safe 
	vibration.wLeftMotorSpeed = 0;						// Use any value between 0-65535 
	vibration.wRightMotorSpeed = 0;
	XInputSetState(0, &vibration);
}
bool ControllerManager::VibrateOn(int powerLeft, int powerRight)
{
	if (powerLeft>0 && powerLeft<65535 && powerRight>0 && powerRight<65535)
	{
		// Vibration value must be between 0 and 65535 
		ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));	// Clear out the chuink of data to be safe 
		vibration.wLeftMotorSpeed = powerLeft;				// Use any value between 0-65535
		vibration.wRightMotorSpeed = powerRight;
		XInputSetState(0, &vibration);
		return true;
	}
	else
		return false;
}
#pragma endregion

#pragma region Accessors
ControllerManager * ControllerManager::GetInstance()
{
	// If instance has been created, return it
	if (controllerManagerInstance) return controllerManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		controllerManagerInstance = new ControllerManager;
		return controllerManagerInstance;
	}
}
#pragma endregion