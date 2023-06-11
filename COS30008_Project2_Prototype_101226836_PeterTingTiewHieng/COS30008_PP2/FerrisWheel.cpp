#include "FerrisWheel.h"

FerrisWheel::FerrisWheel(int c, int e, int f, int b) :Attractions(c, e, f, b) {}

FerrisWheel::~FerrisWheel() {}

void FerrisWheel::showInformation()
{
	cout << "Ferris Wheel Lvl " << lvl << ", Base Earnings Per Day: " << earnings << " Base Fame Per Day: " << increasedFame << ", Operating Days: " << operatingDays << ", Bonus Rate: " << bonus << " (Status: " << getBuildingStatus() << ")" << endl;
}

void FerrisWheel::accept(AttractionsVisitor& v) { v.visit(this); }