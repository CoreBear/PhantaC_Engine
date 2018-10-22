#ifndef _GAME_STATE_H
#define _GAME_STATE_H

// My Headers
#include "GameManager.h"

class GameState
{
public:
	// Update
	virtual void UpdateState(float deltaTime) { return; }
};
class GameRunning : public GameState
{
	GameManager*		gameManagerPtr;

public:
	// Initialization
	GameRunning() { return; }
	GameRunning(GameManager* gameManager) : gameManagerPtr(gameManager) { return; }
	
	// Update
	void UpdateState(float deltaTime) override { gameManagerPtr->MainGameUpdate(deltaTime); }
};
class GamePaused : public GameState
{

};

#endif