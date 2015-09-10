/********************************************************************************
 * Samuel Marrujo
 * hw3.cpp
 * 02/05/13
 * This program plays four-card solitaire. It's a game!
 ********************************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//******************** Card Class

enum suits { diamond, club, heart, spade };

class Card {
    // private by default
    int      rank;        // rank of card
    suits    suit;        // suit of card
public:
    // constructors
    Card();               // initialize a card with default values
    Card(suits, int);     // initialize a card with given values
    // accessors
    int getRank() { return rank; } // an in-line function
    suits getSuit() { return suit; }
    // mutators
    void setRank(int rv) { rank = rv; }
    void setSuit(suits sv) { suit = sv; }
}; // Card
 
ostream & operator<<(ostream &, Card );
//***************End Card Class
//******************** Deck Class

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

//*****************End Deck Class


//******************** Random Class

class RandomInteger {
    public:
        RandomInteger();
        unsigned int operator()(unsigned int max);
}; // RandomInteger

//*****************End Random Class

//******************** Card Functions
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
//********************* Card functions

//******************** Deck Functions
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

//******************** Deck Functions

//******************** Random Functions
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
//******************** Random Functions


//Used to determine the maximum size of the columns
//Based off of the Maximum Size Algorithm
int max_size(const vector<vector<Card> > &vector) {
    int size=0;
    for (int i = 0; i < 4; i++) {
        if (vector[i].size() > 0)
            size = vector[i].size();
    }
    return size;
}

void solitaire(unsigned int &discard, vector<vector<Card> > &column, Deck &theDeck) {
    int choice(0);                     // Choice for the column               
    while (!theDeck.isEmpty()) {
        
        cout << "Choose a card to discard (-1 to quit, 0 to draw 4 more cards): \n";
        cout << setw(0) << "Col 1" << setw(20) << "Col 2" << setw(20) << "Col 3" << setw(20) << "Col 4"  << endl;
        int maximum_size = max_size(column);
        for (int j = 0; j < maximum_size; j++) {
            for (int i = 0; i < 4; i++) {
                if (j < column[i].size())
                    cout << setw(9) << column[i][j];
                else
                    cout << "\t\t";    
            }    
            cout << endl;
        }
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice < -1 && choice > 4) {
            cout << "Must be a valid answer: -1, 0, or 1-4 to discard a card from it's respective column. \n";
        }
        else if (choice == -1) {
            cout << "Thanks for playing! \n";
            break;
        }//end of choice(-1)
        else if (choice == 0) {
            for (int i = 0; i < 4; i++) {
                Card card = theDeck.draw();
                column[i].push_back(card);
            }
        }//end of choice(0)
        else if (choice > 0 && choice < 5) {
            for (int i = 0; i < 4; i++) {
                if (column[choice-1].back().getSuit() == column[i].back().getSuit()) { 
                    if (column[choice-1].back().getRank() < column[i].back().getRank()) {
                        column[choice-1].pop_back();
                        discard++;
                    }
                }
            }
            if (column[choice-1].back().getRank() == 14) {
                int choice_two(4); //Some value to enter the loop
                while ((choice_two > 0 && choice_two < 5) || choice_two == -1) {
                    cout << "Where do you want to move the Ace to? (Choose the column): \n";
                    cin >> choice_two;
                    if (choice_two > 0 && choice_two < 5) {
                        if ((column[choice-1].back().getRank() == column[choice_two-1].back().getRank()) || (column[choice_two-1].empty())) {
                            column[choice_two-1].push_back(column[choice-1].back());
                            column[choice-1].pop_back();
                            break;
                        }
                    }
                    if (choice_two < 1 && choice_two > 4)
                        choice_two = -1; //resets loop
                }     
            }
        }//end of choice(1-4)
      /*  else if (choice == 2) {
            for (int i = 0; i < 4; i++) {
                if (column[1].back().getSuit() == column[i].back().getSuit()) { 
                    if (column[1].back().getRank() < column[i].back().getRank()) {
                        column[1].pop_back();
                        discard++;
                    }
                }
            }
            if (column[1].back().getRank() == 14) {
                int choice_two(4); //Some value to enter the loop
                while ((choice_two > 0 && choice_two < 5) || choice_two == -1) {
                    cout << "Where do you want to move the Ace to? (Choose the column): \n";
                    cin >> choice_two;
                    if (choice_two > 0 && choice_two < 5) {
                        if ((column[1].back().getRank() == column[choice_two-1].back().getRank()) || (column[choice_two-1].empty())) {
                            column[choice_two-1].push_back(column[1].back());
                            column[1].pop_back();
                            break;
                        }
                    }
                    if (choice_two < 1 && choice_two > 4)
                        choice_two = -1; //resets loop
                }     
            }
        }//end of choice(2)
        else if (choice == 3) {
            for (int i = 0; i < 4; i++) {
                if (column[2].back().getSuit() == column[i].back().getSuit()) { 
                    if (column[2].back().getRank() < column[i].back().getRank()) {
                        column[2].pop_back();
                        discard++;
                    }
                }
            }
            if (column[2].back().getRank() == 14) {
                int choice_two(4); //Some value to enter the loop
                while ((choice_two > 0 && choice_two < 5) || choice_two == -1) {
                    cout << "Where do you want to move the Ace to? (Choose the column): \n";
                    cin >> choice_two;
                    if (choice_two > 0 && choice_two < 5) {
                        if ((column[2].back().getRank() == column[choice_two-1].back().getRank()) || (column[choice_two-1].empty())) {
                            column[choice_two-1].push_back(column[2].back());
                            column[2].pop_back();
                            break;
                        }
                    }
                    if (choice_two < 1 && choice_two > 4)
                        choice_two = -1; //resets loop
                }    
            }
        }//end of choice(3)
        else if (choice == 4) {
            for (int i = 0; i < 4; i++) {
                if (column[3].back().getSuit() == column[i].back().getSuit()) { 
                    if (column[3].back().getRank() < column[i].back().getRank()) {
                        column[3].pop_back();
                        discard++;
                    }
                }
            }
            if (column[3].back().getRank() == 14) {
                int choice_two(4); //Some value to enter the loop
                while ((choice_two > 0 && choice_two < 5) || choice_two == -1) {
                    cout << "Where do you want to move the Ace to? (Choose the column): \n";
                    cin >> choice_two;
                    if (choice_two > 0 && choice_two < 5) {
                        if ((column[3].back().getRank() == column[choice_two-1].back().getRank()) || (column[choice_two-1].empty())) {
                            column[choice_two-1].push_back(column[3].back());
                            column[3].pop_back();
                            break;
                        }
                    }
                    if (choice_two < 1 && choice_two > 4)
                        choice_two = -1; //resets loop
                }     
            }
        }*///end of choice(4) 
        //end of while
    }
}// Solitaire game

/*
void last_stand(unsigned int &discard, vector<vector<Card> > &column, Deck &theDeck) {
    int maximum_size = max_size(column);
    int choice_three(0);
    while(maximum_size > 0 && choice_three != 1){
        cout << "The deck is out of cards. \n";
        cout << "Do you want to give up? (0 = No, 1 = Yes): ";
        cin >> choice_three;
        solitaire(discard, column, theDeck);
    }// Basically used to keep the player going until they quit with -1
}
*/
main() {
    unsigned int discard(0); //Counter for cards discarded
    vector<vector<Card> > column(4);
    Deck theDeck;                      // Create a deck
    theDeck.shuffle();
    for (int i = 0; i < 4; i++) {
        Card card = theDeck.draw();
        column[i].push_back(card);
    }
    solitaire(discard, column, theDeck);
    if ((discard == 48) && (column[0].front().getRank() == 14) && (column[1].front().getRank() == 14) && (column[2].front().getRank() == 14) && (column[3].front().getRank() == 14))
        cout << "You win!\n";
    else 
        cout << "You lost!\n";
    cin.ignore();
    cin.get();
    return 0;
}
