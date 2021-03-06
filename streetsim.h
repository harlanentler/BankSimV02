#ifndef STREETSIM_H
#define STREETSIM_H

#include "custsim.h"

//DATA STRUCTURES
#include "twList.h"

class streetSim
{
public:
    streetSim();

    twList<custSim> &step(twList<custSim> &listIn);
private:
    int count;
    twList<custSim> list;

    void populate();
};

#endif // STREETSIM_H
