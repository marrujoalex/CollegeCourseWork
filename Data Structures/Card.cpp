#include <iostream>
#include "Card.h"

using namespace std;

Card::Card()
{
    rank = 2;
    suit = spade;
} // constructor

Card::Card(suits sv, int rv)
{
    rank = rv;
    suit = sv;
} // constructor

// output a textual presentation of a Card
ostream & operator<<(ostream & out, Card aCard)
{
    switch (int rank = aCard.getRank()) {
        case 2:  out << "2"; break;
        case 11: out << "Jack"; break;
        case 12: out << "Queen"; break;
        case 13: out << "King"; break;
        case 14: out << "Ace"; break;
        default: out << rank;
    }

    switch (suits suit = aCard.getSuit()) {
        case diamond: out << " of Diamonds"; break;
        case spade:   out << " of Spades"; break;
        case heart:   out << " of Hearts"; break;
        case club:    out << " of Clubs"; break;
    }
    return out;
} // operator<<
