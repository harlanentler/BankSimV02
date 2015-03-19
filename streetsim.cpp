#include "streetsim.h"

streetSim::streetSim()
{
    count = 0;
}

twList<custSim>& streetSim::step(twList<custSim> &listIn)
{
    list.pushBack(listIn);
    populate();
    return list;
}

void streetSim::populate()
{
    list.pushBack(custSim(++count));
}
