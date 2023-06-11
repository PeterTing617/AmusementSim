#pragma once
#include "StateStack.h"
#include "MainMenuState.h"
#include "GameState.h"

class Game
{
private:
	StateStack states;

public:
	// Game Constructor and Destructor
	Game();
	~Game();

	// Core
	void run();
};