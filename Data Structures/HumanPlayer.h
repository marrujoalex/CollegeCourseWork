#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Card.h"
#include "Deck.h"

class HumanPlayer: public Player {
public:
    HumanPlayer(Deck &deck): Player(deck) {} // kay 8/20/98
                                             // calls base constructor
    Card draw(); // another draw()!
}; // HumanPlayer

#endif
