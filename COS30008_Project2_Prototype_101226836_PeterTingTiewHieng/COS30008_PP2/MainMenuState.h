#pragma once
#include "State.h"

class MainMenuState :
    public State
{
private:

public:
    // Constructor and Destructor
    MainMenuState();
    ~MainMenuState();

    // Functions
    void menu();
    void run();
};

