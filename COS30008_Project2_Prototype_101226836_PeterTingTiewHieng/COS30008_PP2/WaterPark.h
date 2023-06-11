#pragma once
#include "Attractions.h"

class WaterPark :
    public Attractions
{
private:

public:
    // Constructor and destructor
    WaterPark(int c, int e, int f, int b);
    ~WaterPark();

    // Functions
    void showInformation();
    // Accept visitor object
    void accept(AttractionsVisitor& v);
};