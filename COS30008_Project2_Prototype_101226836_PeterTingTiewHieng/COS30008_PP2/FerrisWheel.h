#pragma once
#include "Attractions.h"

class FerrisWheel :
    public Attractions
{
private:

public:
    // Constructor and destructor
    FerrisWheel(int c, int e, int f, int b);
    ~FerrisWheel();

    // Functions
    void showInformation();
    // Accept visitor object
    void accept(AttractionsVisitor& v);
};

