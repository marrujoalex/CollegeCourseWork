#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"

using namespace std;

class Deck {
    Card cards[52];       // deck of 52 cards
    int topCard;          // 1 + index of next available card
public:
    Deck();
    // shuffle uses the generic algorithm random_shuffle from STL
    void shuffle();
    bool isEmpty() { return topCard <= 0; }
    Card draw();          // return next card
}; // Deck

#endif
