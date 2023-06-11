#include "AttractionsFactory.h"

AttractionsFactory::AttractionsFactory() {}

AttractionsFactory::~AttractionsFactory() {}

Attractions* AttractionsFactory::buildAttractions(string i)
{
	if (i == "1")
	{
		return new FerrisWheel(2, 1, 2, 1);
	}
	else if (i == "2")
	{
		return new WaterPark(10, 5, 10, 5);
	}
	else if (i == "3")
	{
		return new RollerCoaster(20, 10, 20, 10);
	}
	else {
		return new FerrisWheel(2, 1, 2, 1);
	}
}
