#include "simulation.h"

simulation::simulation()
{
}

void simulation::run()
{
    for(int i=480; i>0; i--)
    {
        step();
        cout << list[ list.size()-1 ].getNum() << endl;
    }
}

void simulation::step()
{
    list.pushBack( street.step(list) );
}
