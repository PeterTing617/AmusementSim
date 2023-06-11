#include "GameState.h"

void GameState::initPark()
{
    cout << "Enter theme park name:" << endl;
    cout << ">>";
    clearInput();
    while (userInput.empty())
    {
        getline(cin, userInput);
    }
    name = userInput;
    cout << endl;
}

void GameState::initLevel()
{
    vector<string> level1 = { "FerrisWheel" };
    vector<string> level2 = { "FerrisWheel","WaterPark" };
    vector<string> level3 = { "FerrisWheel","WaterPark","RollerCoaster" };
    q.enqueue(1, level1, 2, 50);
    q.enqueue(2, level2, 4, 150);
    q.enqueue(3, level3, 6, 250);
}

GameState::GameState()
{
    initPark();
    initLevel();
    day = 1;
    gold = 5;
    fame = 0;
    lvl = q.dequeue();
}

GameState::~GameState() { delete lvl; }

void GameState::menu()
{
    cout << "Day " << day << endl;
    cout << "[1] Build Buildings" << endl;
    cout << "[2] Upgrade Buildings" << endl;
    cout << "[3] Remove Buildings" << endl;
    cout << "[4] Expand Park" << endl;
    cout << "[5] Theme Park Statistic & Information" << endl;
    cout << "[6] Next Day" << endl;
    cout << "[7] Quit" << endl;
    cout << ">>";
    clearInput();
    vector<string> validInput = { "1","2","3","4","5","6","7" };
    while (!checkValid(validInput))
    {
        getline(cin, userInput);
    }
    cout << endl;
}

bool GameState::checkSufficientGold(int g)
{
    if (gold >= g)
    {
        gold -= g;
        return true;
    }
    else {
        cout << "Insufficient funds\n" << endl;
        return false;
    }
}

void GameState::checkProceedLevel()
{
    if (!lvl->lastLvl)
    {
        if (fame >= lvl->proceedNextLvl)
        {
            delete lvl;
            lvl = q.dequeue();
            cout << "Level Up to Level " << lvl->level << endl;
        }
    }
}

void GameState::buildOperation()
{
    AttractionsFactory at;
    vector<Attractions*> samples;
    cout << "Enter buildings to build:" << endl;
    int buildOptions = 1;
    int ferrisI = 0;
    int waterI = 0;
    int rollerI = 0;
    for (size_t i = 0; i < lvl->unlockedBuildings.size(); i++)
    {
        if (lvl->unlockedBuildings[i] == "FerrisWheel")
        {
            ferrisI = samples.size();
            samples.push_back(at.buildAttractions("1"));
            cout << "[" << buildOptions << "] Ferris Wheel - " << samples[ferrisI]->getCost() << " Gold (" << samples[ferrisI]->getBuildTime() << " Day)" << endl;
            buildOptions++;
        }
        else if (lvl->unlockedBuildings[i] == "WaterPark") {
            waterI = samples.size();
            samples.push_back(at.buildAttractions("2"));
            cout << "[" << buildOptions << "] Water Park - " << samples[waterI]->getCost() << " Gold (" << samples[waterI]->getBuildTime() << " Day)" << endl;
            buildOptions++;
        }
        else if (lvl->unlockedBuildings[i] == "RollerCoaster") {
            rollerI = samples.size();
            samples.push_back(at.buildAttractions("3"));
            cout << "[" << buildOptions << "] Roller Coaster - " << samples[rollerI]->getCost() << " Gold (" << samples[rollerI]->getBuildTime() << " Day)" << endl;
            buildOptions++;
        }
    }
    cout << "[" << buildOptions << "] Quit" << endl;
    cout << ">>";
    clearInput();
    vector<string> validInput;
    for (size_t i = 0; i < size_t(buildOptions); i++)
    {
        validInput.push_back(to_string(i + 1));
    }
    while (!checkValid(validInput))
    {
        getline(cin, userInput);
        cout << endl;
        if (checkValid(validInput))
        {
            if (userInput == "1" && userInput != to_string(buildOptions))
            {
                if (!checkSufficientGold(samples[ferrisI]->getCost()))
                {
                    userInput = "";
                }
                else {
                    park.addAttractions(userInput);
                    cout << "Building Ferris Wheel\n" << endl;
                }
            }
            if (userInput == "2" && userInput != to_string(buildOptions))
            {
                if (!checkSufficientGold(samples[waterI]->getCost()))
                {
                    userInput = "";
                }
                else {
                    park.addAttractions(userInput);
                    cout << "Building Water Park\n" << endl;
                }
            }
            if (userInput == "3" && userInput != to_string(buildOptions))
            {
                if (!checkSufficientGold(samples[rollerI]->getCost()))
                {
                    userInput = "";
                }
                else {
                    park.addAttractions(userInput);
                    cout << "Building Roller Coaster\n" << endl;
                }
            }
        }
    }
    for (size_t i = 0; i < samples.size(); i++)
    {
        delete samples[i];
    }
}

void GameState::upgradeOperation()
{
    cout << "Enter buildings to upgrade:" << endl;
    park.readAttractionInfo();
    cout << "[" << park.parkSize() + 1 << "] Quit" << endl;
    cout << ">>";
    clearInput();
    vector<string> validInput;
    for (size_t i = 0; i < size_t(park.parkSize() + 1); i++)
    {
        validInput.push_back(to_string(i + 1));
    }
    while (!checkValid(validInput))
    {
        getline(cin, userInput);
        cout << endl;
        if (checkValid(validInput))
        {
            if (userInput != to_string(park.parkSize() + 1))
            {
                gold = park.upgradeAttractions(userInput, gold);
            }
        }
    }
}

void GameState::removeOperation()
{
    cout << "Enter buildings to remove:" << endl;
    park.readAttractionInfo();
    cout << "[" << park.parkSize() + 1 << "] Quit" << endl;
    cout << ">>";
    clearInput();
    vector<string> validInput;
    for (size_t i = 0; i < size_t(park.parkSize() + 1); i++)
    {
        validInput.push_back(to_string(i + 1));
    }
    while (!checkValid(validInput))
    {
        getline(cin, userInput);
        cout << endl;
        if (checkValid(validInput))
        {
            if (userInput != to_string(park.parkSize() + 1))
            {
                gold += park.removeAttractions(userInput);
            }
        }
    }
}

void GameState::expandOperation()
{
    int expandC = (park.limitAttractions() + 1) * 10;
    cout << "Max Attractions: " << park.limitAttractions() << " to " << park.limitAttractions() + 1 << endl;
    cout << "Cost: " << expandC << " gold" << endl;
    cout << "[1] Confirm" << endl;
    cout << "[2] Cancel" << endl;
    cout << ">>";
    clearInput();
    vector<string> validInput = { "1","2" };
    while (!checkValid(validInput))
    {
        getline(cin, userInput);
        cout << endl;
        if (userInput != "2")
        {
            if (!checkSufficientGold(expandC))
            {
                userInput = "";
            }
            else {
                park.increaseLimit(1);
                cout << "Amusement Park expanded to a size of " << park.limitAttractions() << "\n" << endl;
            }
        }
    }
}

void GameState::run()
{
    menu();
    if (userInput == "1")
    {
        if (park.parkSize() == park.limitAttractions())
        {
            cout << "You have reached your limit. Please expand to build more attractions.\n" << endl;
        }
        else {
            buildOperation();
        }
    }
    else if (userInput == "2")
    {
        if (park.parkSize() == 0)
        {
            cout << "No buildings to upgrade\n" << endl;
        }
        else {
            upgradeOperation();
        }
    }
    else if (userInput == "3")
    {
        if (park.parkSize() == 0)
        {
            cout << "No buildings to remove\n" << endl;
        }
        else {
            removeOperation();
        }
    }
    else if (userInput == "4")
    {
        if (park.limitAttractions() == lvl->maxB)
        {
            cout << "Level Up to expand park.\n" << endl;
        }
        else {
            expandOperation();
        }
    }
    else if (userInput == "5")
    {
        cout << "Theme Park Name: " << name << endl;
        cout << "Level: " << lvl->level << endl;
        cout << "Total Days Opened: " << day << endl;
        cout << "Available Gold: " << gold << endl;
        cout << "Fame: " << fame << endl;
        cout << "Maximum Attractions: " << park.limitAttractions() << endl;
        cout << "Available Attractions: " << endl;
        if (park.parkSize() == 0)
        {
            cout << "None\n" << endl;
        }
        else {
            park.readAttractionInfo();
            cout << endl;
        }
    }
    else if (userInput == "6")
    {
        tuple<int, int> result = park.proceedNextDay();
        gold += get<0>(result);
        fame += get<1>(result);
        cout << "Day " << day << " Statistic:" << endl;
        cout << "Today earnings: " << get<0>(result) << " gold" << endl;
        cout << "Increased fame: " << get<1>(result) << endl;
        cout << "Current gold: " << gold << endl;
        cout << "Current fame: " << fame << endl;
        checkProceedLevel();
        cout << "Proceed to the next day\n" << endl;
        day++;
    }
    else if (userInput == "7")
    {
        endState();
    }
}