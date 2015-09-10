#include <iostream>
#include <algorithm>

#include "Card.h"
#include "Deck.h"
#include "Random.h"

using namespace std;

extern RandomInteger randomizer;

Deck::Deck()
{
    topCard = 0;
    for (int i = 2; i <= 14; i++) {
        Card c1(diamond, i), c2(spade, i), c3(heart, i), c4(club, i);
        cards[topCard++] = c1;
        cards[topCard++] = c2;
        cards[topCard++] = c3;
        cards[topCard++] = c4;
    }
} // constructor

Card Deck::draw()
{
    if (!isEmpty())
        return cards[--topCard];
    else { 
        Card spadeTwo(spade, 2);
        return spadeTwo;
    }
} // draw

void Deck::shuffle()
{
    random_shuffle(cards, cards+52, randomizer);
} // shuffle
