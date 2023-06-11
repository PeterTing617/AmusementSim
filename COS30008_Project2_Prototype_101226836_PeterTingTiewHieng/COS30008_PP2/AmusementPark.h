#pragma once
#include "AttractionsFactory.h"
#include "BonusTree.h"

class AmusementPark
{
private:
	vector<Attractions*> attractions;
	AttractionsFactory atF;
	BonusTree* headT;
	int maxAttractions;

	void initTree();

public:
	// Constructor and destructor
	AmusementPark();
	~AmusementPark();

	// Functions
	int parkSize();
	int limitAttractions();
	void increaseLimit(int i);
	void addAttractions(string i);
	int removeAttractions(string i);
	int upgradeAttractions(string i, int g);
	void updateBonus();
	void readAttractionInfo();
	tuple<int, int> proceedNextDay();
};