#ifndef _GAME_STATE_H
#define _GAME_STATE_H

// My Headers
#include "GameController.h"

class GameState
{
public:
	// Update
	virtual void UpdateState() { return; }
};
class GameRunning : public GameState
{
	GameController*		gameControllerPtr;

public:
	// Initialization
	GameRunning() { return; }
	GameRunning(GameController* gameController) : gameControllerPtr(gameController) { return; }
	
	// Update
	void UpdateState() override { gameControllerPtr->MainGameUpdate(); }
};
class GamePaused : public GameState
{

};

#endif