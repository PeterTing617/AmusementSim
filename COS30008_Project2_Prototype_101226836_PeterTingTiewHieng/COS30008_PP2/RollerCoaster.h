#pragma once
#include "Attractions.h"

class RollerCoaster :
    public Attractions
{
private:

public:
    // Constructor and destructor
    RollerCoaster(int c, int e, int f, int b);
    ~RollerCoaster();

    // Functions
    void showInformation();
    // Accept visitor object
    void accept(AttractionsVisitor& v);
};