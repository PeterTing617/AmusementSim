#pragma once
#include "State.h"
#include "AmusementPark.h"
#include "LevelQueue.h"  

class GameState :
    public State
{
private:
    string name;
    int day;
    int gold;
    int fame;

    AmusementPark park;
    LevelQueue q;
    Level* lvl;

    // Init SandBox
    void initPark();

    // Init SandBox Level
    void initLevel();

public:
    // Constructor and destructor
    GameState();
    ~GameState();

    // Functions
    void menu();

    bool checkSufficientGold(int g);
    void checkProceedLevel();

    void buildOperation();
    void upgradeOperation();
    void removeOperation();
    void expandOperation();

    void run();
};

