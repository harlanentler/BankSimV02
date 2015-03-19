#ifndef SIMULATION_H
#define SIMULATION_H

//MANAGED SIMULATION CLASSES
#include "streetsim.h"

#include "custsim.h"

//DATA STRUCTURES
#include "twList.h"

class simulation
{
public:
    simulation();

    void run();

private:
    streetSim street;
    twList<custSim> list;

    void step();
};

#endif // SIMULATION_H
