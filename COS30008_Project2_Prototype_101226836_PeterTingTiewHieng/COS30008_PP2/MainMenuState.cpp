#include "MainMenuState.h"

MainMenuState::MainMenuState() {}

MainMenuState::~MainMenuState() {}

void MainMenuState::menu() {
    cout << "Amusement Park Simulator C++" << endl;
    cout << "****************************" << endl;
    cout << "[1] Play Game" << endl;
    cout << "[2] Credits" << endl;
    cout << "[3] Quit" << endl;
    cout << ">>";
    clearInput();
    vector<string> validInput = { "1","2","3" };
    while (!checkValid(validInput))
    {
        getline(cin, userInput);
    }
    cout << endl;
}

void MainMenuState::run() {
    menu();
    if (userInput == "1")
    {
        switchState = true;
        switchTarget = "GAME";
    }
    if (userInput == "2")
    {
        cout << "Created by Peter Ting Tiew Hieng (101226836)" << endl;
        cout << "COS30008 Programming Project 2 S2 2021\n" << endl;
    }
    if (userInput == "3")
    {
        endState();
    }
}