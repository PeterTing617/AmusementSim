#include "LevelQueue.h"

LevelQueue::LevelQueue() {
	head = nullptr;
	totalLevel = 0;
}

LevelQueue::~LevelQueue() {
	Level* deleteNext = nullptr;
	Level* deleteCurrent = head;
	for (int i = 0; i < totalLevel; i++) {
		if (i == 0)
		{
			deleteNext = deleteCurrent->next;

			delete deleteCurrent;
		}
		else {
			deleteCurrent = deleteNext;
			deleteNext = deleteCurrent->next;

			delete deleteCurrent;
		}
	}
}

bool LevelQueue::isEmpty() { return totalLevel == 0; }

int LevelQueue::size() { return totalLevel; }

void LevelQueue::enqueue(int l, vector<string> available, int max, int p) { 
	Level* new_Level = new Level;
	new_Level->level = l;
	new_Level->unlockedBuildings = available;
	new_Level->maxB = max;
	new_Level->proceedNextLvl = p;

	totalLevel++;

	if (head == nullptr)
	{
		new_Level->lastLvl = true;
		head = new_Level;
	}
	else {
		Level* target = head;
		for (int i = 0; i < totalLevel - 2; i++)
		{
			target = target->next;
		}
		target->lastLvl = false;
		new_Level->lastLvl = true;
		target->next = new_Level;
	}
}

Level* LevelQueue::dequeue()
{
	if (!isEmpty())
	{
		Level* Result = head;
		totalLevel--;
		head = head->next;
		return Result;
	}
	else {
		return nullptr;
	}
}