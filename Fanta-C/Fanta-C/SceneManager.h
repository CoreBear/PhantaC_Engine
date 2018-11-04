#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"
#include "Renderer.h"

// System Headers
#include <vector>

// Forward Declaration
class AutonomousAgent;
class Camera;
class ObjectTransform;
class RenderableObject;

class SceneManager
{
	class Audio*					audio;					
	Camera*							cameraPtr;
	class Logic*					logic;					// The actual running of the scene (game update. i.e. scene autonomousAgents)
	class PhysicsMain*				physicsMain;			
	class Player*					playerPtr;
	Renderer*						renderer;
	std::vector<AutonomousAgent*>	autonomousAgents;		// Objects that can move. Contents of this container are not necessarily visible
	std::vector<Agent*>				renderableAgents;		// Objects that can be seen in the game world
	std::vector<Agent*>				staticAgents;			// Objects that do not move. Contents of this container are not necessarily visible

	void CreateObjectAndStore(Agent* object, bool autonomous, bool renderable);

public:
	// Initialization
	SceneManager(class InputManager* inputManager, ushort* clientDimensions, HWND* windowHandle, uchar targetFPS);

	// Update
	void Update(float deltaTime);

	// Accessors
	std::vector<AutonomousAgent*>* GetAutonomousAgents() { return &autonomousAgents; }
	std::vector<Agent*>* GetStaticAgents() { return &staticAgents; }

	// Clean up
	~SceneManager();
};

#endif