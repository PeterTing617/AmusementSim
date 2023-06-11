#pragma once
#include "AttractionsVisitor.h"

class Attractions
{
protected:
	int cost;
	int earnings;
	int increasedFame;

	int lvl;
	int operatingDays;
	int bonus;

	int buildingTime;
	int upgradeTime;

public:
	// Constructor and destructor
	Attractions(int c, int e, int f, int b);
	virtual ~Attractions();

	// getters
	int getCost();
	int getEarnings();
	int getFame();
	int getLevel();
	int getOperatingDays();
	int getBonus();
	int getBuildTime();
	int getUpgradeTime();
	string getBuildingStatus();

	// setters
	void setEarnings(int e);
	void setFame(int f);
	void setBonus(int v);
	void setUpgradeTime(int u);

	// functions
	void upgradeLvl();
	void decreaseUpgradeT();
	void decreaseBuildingT();
	void increaseOperatingDays();
	virtual void showInformation() = 0;

	// accept visitor object
	virtual void accept(AttractionsVisitor& v) = 0;
};

