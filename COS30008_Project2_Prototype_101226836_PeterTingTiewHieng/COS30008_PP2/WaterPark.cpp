#include "WaterPark.h"

WaterPark::WaterPark(int c, int e, int f, int b) :Attractions(c, e, f, b) {}

WaterPark::~WaterPark() {}

void WaterPark::showInformation()
{
	cout << "Water Park Lvl " << lvl << ", Base Earnings Per Day: " << earnings << " Base Fame Per Day: " << increasedFame << " , Operating Days: " << operatingDays << ", Bonus Rate: " << bonus << " (Status: " << getBuildingStatus() << ")" << endl;
}

void WaterPark::accept(AttractionsVisitor& v) { v.visit(this); }