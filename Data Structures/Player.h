#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"

class Player {
protected:    	       // kay 8/20/98, was private
    Card myCards[3];
    int myScore;
    int removedCard;
public:
    Player(Deck &);
    Card draw();       // another draw()!
    void addPoints(int howMany) { myScore += howMany; }
    int score() { return myScore; }
    void replaceCard(Deck &aDeck) { myCards[removedCard] = aDeck.draw(); }
}; // Player

#endif
