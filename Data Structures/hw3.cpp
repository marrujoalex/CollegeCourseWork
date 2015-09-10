/********************************************************************************
 * Samuel Marrujo
 * hw3.cpp
 * 02/05/13
 * This program plays four-card solitaire. It's a game!
 ********************************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Random.h"

using namespace std;

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

main() {
    Deck theDeck; // create a deck
    theDeck.shuffle();
    vector<vector<Card> > column(4);
    int choice(0); // choice for the column               
    unsigned int discard(0); // Counter for discard
    for (int i = 0; i < 4; i++) {
        Card card = theDeck.draw();
        column[i].push_back(card);
    }
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
        //end of while
    }
    if ((discard == 48) && (column[0].front().getRank() == 14) && (column[1].front().getRank() == 14) && (column[2].front().getRank() == 14) && (column[3].front().getRank() == 14))
        cout << "You win!\n";
    else 
        cout << "You lost!\n";
    return 0;
}
