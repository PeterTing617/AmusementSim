#include "Attractions.h"

Attractions::Attractions(int c, int e, int f, int b)
{
	cost = c;
	earnings = e;
	increasedFame = f;
	buildingTime = b;

	lvl = 1;
	upgradeTime = 0;
	operatingDays = 0;
	bonus = 1;
}

Attractions::~Attractions() {}

int Attractions::getCost() { return cost; }

int Attractions::getEarnings() { return earnings; }

int Attractions::getFame() { return increasedFame; }

int Attractions::getLevel() { return lvl; }

int Attractions::getOperatingDays() { return operatingDays; }

int Attractions::getBonus() { return bonus; }

int Attractions::getBuildTime() { return buildingTime; }

int Attractions::getUpgradeTime() { return upgradeTime; }

string Attractions::getBuildingStatus()
{
	if (buildingTime != 0)
	{
		return "Building - " + to_string(buildingTime) + " days";
	}
	else if (upgradeTime != 0)
	{
		return "Upgrading - " + to_string(upgradeTime) + " days";
	}
	else {
		return "Completed";
	}
}

void Attractions::setEarnings(int e) { earnings = e; }

void Attractions::setFame(int f) { increasedFame = f; }

void Attractions::setBonus(int v) { bonus = v; }

void Attractions::setUpgradeTime(int u) { upgradeTime = u; }

void Attractions::upgradeLvl() { lvl++; }

void Attractions::decreaseUpgradeT() { upgradeTime--; }

void Attractions::decreaseBuildingT() { buildingTime--; }

void Attractions::increaseOperatingDays() { operatingDays++; }