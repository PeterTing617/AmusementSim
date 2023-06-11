#include "Game.h"

Game::Game() { states.push(new MainMenuState()); }

Game::~Game() {}

void Game::run()
{
	while (!states.isEmpty())
	{
		states.top()->run();
		if (states.top()->getSwitchState())
		{
			states.top()->reverseSwitch();
			if (states.top()->getSwitchTarget() == "GAME")
			{
				states.push(new GameState());
			}
		}
		if (states.top()->getQuit())
		{
			delete states.top();
			states.pop();
		}
	}
	cout << "Program terminates\n" << endl;
}