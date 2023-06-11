#include "RollerCoaster.h"

RollerCoaster::RollerCoaster(int c, int e, int f, int b) :Attractions(c, e, f, b) {}

RollerCoaster::~RollerCoaster() {}

void RollerCoaster::showInformation()
{
	cout << "Roller Coaster Lvl " << lvl << ", Base Earnings Per Day: " << earnings << " Base Fame Per Day: " << increasedFame << ", Operating Days: " << operatingDays << ", Bonus Rate: " << bonus << " (Status: " << getBuildingStatus() << ")" << endl;
}

void RollerCoaster::accept(AttractionsVisitor& v) { v.visit(this); }