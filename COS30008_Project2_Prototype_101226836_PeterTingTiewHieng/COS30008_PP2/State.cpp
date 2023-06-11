#include "State.h"

State::State()
{
	userInput = "";
	switchTarget = "";
	quit = false;
	switchState = false;
}

State::~State() {}

bool State::getQuit() { return quit; }

bool State::getSwitchState() { return switchState; }

string State::getSwitchTarget() { return switchTarget; }

void State::reverseSwitch() { switchState = false; }

void State::endState() { quit = true; }

void State::clearInput() { userInput = ""; }

bool State::checkValid(vector<string> valid)
{
	bool valInput = false;

	for (size_t i = 0; i < valid.size(); i++) {
		if (userInput == valid[i]) {
			valInput = true;
			break;
		}
	}

	return valInput;
}