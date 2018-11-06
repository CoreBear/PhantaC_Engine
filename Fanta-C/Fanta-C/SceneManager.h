#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"
#include "Renderer.h"

// System Headers
#include <vector>

// Forward Declarations
class Agent;

class SceneManager
{
	class AudioManager*			audioManagerPtr;					
	class Camera*				cameraPtr;
	class IntelligenceManager*	intelligenceManagerPtr;	// The actual running of the scene (game update. i.e. AI)
	class PhysicsManager*		physicsManagerPtr;			
	class Renderer*				rendererPtr;
	std::vector<Agent*>			autonomousAgents;		// Objects that can think. Contents of this container are not necessarily visible
	
	// Leave as "Agent", becuase the collider doesn't store transform information
	std::vector<Agent*>			collidableObjects;		// Objects that can collide. Contents of this container are not necessarily visible
	std::vector<class Mesh*>	renderableObjects;		// Objects that can be seen in the game world

public:
	// Initialization
	SceneManager(ushort* clientDimensions, HWND* windowHandle, uchar targetFPS);

	// Update
	void Update(float deltaTime);

	// Clean up
	~SceneManager();
};

#endif