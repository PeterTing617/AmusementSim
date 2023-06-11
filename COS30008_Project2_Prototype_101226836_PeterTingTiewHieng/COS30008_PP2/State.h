#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class State
{
protected:
	string userInput;
	string switchTarget;
	bool quit;
	bool switchState;

public:
	// Constructor and destructor 
	State();
	virtual ~State();

	// Getters
	bool getQuit();
	bool getSwitchState();
	string getSwitchTarget();

	// Functions
	void reverseSwitch();
	void endState();
	void clearInput();

	bool checkValid(vector<string> valid);

	virtual void menu() = 0;
	virtual void run() = 0;
};