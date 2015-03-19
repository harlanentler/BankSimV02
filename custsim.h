#ifndef CUSTSIM_H
#define CUSTSIM_H

#include <iostream>

using namespace std;

class custSim
{
public:
    custSim(int numIn=-1);

    int getNum() const;

    ostream operator <<(ostream &out);

private:
     int number;
};

#endif // CUSTSIM_H
