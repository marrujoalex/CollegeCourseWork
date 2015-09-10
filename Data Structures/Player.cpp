
#include "Player.h"
#include "Deck.h"
#include "Random.h"
#include <iostream>

using namespace std;

extern RandomInteger randomizer;

Player::Player(Deck & aDeck)
{
    myScore = 0;
    for (int i = 0; i < 3; i++)
        myCards[i] = aDeck.draw();
    removedCard = 0;
} // constructor

Card Player::draw()
{
    removedCard = randomizer(3);
    return myCards[removedCard];
} // draw
