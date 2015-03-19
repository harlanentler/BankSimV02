#include "custsim.h"

custSim::custSim(int numIn)
{
    number = numIn;
}

int custSim::getNum() const
{
    return number;
}

ostream custSim::operator <<(ostream& out)
{
    out << "I am customer number " << number << "!" << endl;
}
