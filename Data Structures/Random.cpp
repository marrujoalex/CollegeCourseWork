#include <stdlib.h>       // for rand()
#include <time.h>         // kay 8/20/98, for time()

#include <iostream>
#include "Random.h"

using namespace std;

RandomInteger::RandomInteger()
{
    srand(time(0));       // kay 8/20/98
} // constructor

unsigned int RandomInteger::operator()(unsigned int max)
{
    unsigned int rval = rand();
    return rval % max;
} // operator()

RandomInteger randomizer;
