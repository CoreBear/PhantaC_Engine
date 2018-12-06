#ifndef _CONTROLLER_MANAGER_H
#define _CONTROLLER_MANAGER_H

// System Headers
#include <Winerror.h> 
#include <windows.h> 
#include <XInput.h>					// Defines XBOX controller API 
#pragma comment(lib, "XInput.lib")	// Library containing necessary 360 // functions // // //	i do not know if this actually works yet because i have not had a chance to test it properly! //	when i tried it at home i got a LNK error which the 'XInputGetState' // // // // // // 

class ControllerManager
{
	static ControllerManager*	controllerManagerInstance;
	DWORD						dwResult;		// Used to store if a controller is connected to a controller
	XINPUT_STATE				state;			// Data type that stores all the current states 
	XINPUT_VIBRATION			vibration;

	ControllerManager() { return; }
	ControllerManager(ControllerManager const&) = delete;
	ControllerManager operator=(ControllerManager const&) = delete;

public:
	// Bumpers
	bool LeftBumper();
	bool RightBumper();

	// D-Pad
	bool Down();
	bool Left();
	bool Right();
	bool Up();

	// Face Buttons
	bool A();
	bool B();
	bool X();
	bool Y();

	// Joy Sticks
	bool LeftStickPressed();
	int LeftStickX();
	int LeftStickY();
	bool RightStickPressed();
	int RightStickX();
	int RightStickY();

	// Misc
	bool CheckControllerStatus();

	// Triggers
	int LeftTrigger();
	int RightTrigger();

	// Utility Buttons
	bool Back();
	bool Start();

	// Vibrations
	void VibrateOff();
	bool VibrateOn(int powerLeft, int powerRight);

	// Accessors
	static ControllerManager* GetInstance();
};

#endif