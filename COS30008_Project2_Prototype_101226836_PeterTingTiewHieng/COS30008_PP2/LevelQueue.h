#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Singly Linked List - Level
struct Level
{
	int level = 0;
	vector<string> unlockedBuildings;
	int maxB = 0;
	int proceedNextLvl = 0;
	bool lastLvl = false;

	Level* next = nullptr;
};

// Queue for Level
class LevelQueue
{
private:
	int totalLevel;
	Level* head;

public:
	// Constructor and destructor
	LevelQueue();
	~LevelQueue();

	// Functions
	bool isEmpty();
	int size();
	void enqueue(int l, vector<string> available, int max, int p);
	Level* dequeue();
};