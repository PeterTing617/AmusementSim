#pragma once
#include "FerrisWheel.h"
#include "WaterPark.h"
#include "RollerCoaster.h"

class AttractionsFactory
{
public:
	// Constructor and Destructor
	AttractionsFactory();
	~AttractionsFactory();

	// Functions
	// return an attraction object based on the input
	Attractions* buildAttractions(string i);
};

