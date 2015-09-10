#ifndef RANDOM_H
#define RANDOM_H

class RandomInteger {
    public:
        RandomInteger();
        unsigned int operator()(unsigned int max);
}; // RandomInteger

#endif
