#include <string>
#include <cstdlib>
#include <vector>
#include "deck.h"
#include "card.h"

using namespace std;

//Constructor
Deck::Deck(){
    myIndex = 0;
    int count = 0;
    int suitCount = 0;
    while (count < SIZE) {
        while (suitCount <= 3){
            int rankCount = 1;
            while (rankCount <= 13) {
                Card c(rankCount, (Card::Suit)suitCount);
                myCards[count] = c;
                rankCount++;
                count++;
            }
            suitCount++;
        }
    }
}

int Deck::size() const{
    return (SIZE-myIndex);
}

void Deck::shuffle() {
    if (size() < 2) return;
    else {
        for (int i = 0; i < size(); i++) {
            int c1 = rand() % size();
            int c2 = rand() % size();
            Card temp = myCards[c1];
            myCards[c1] = myCards[c2];
            myCards[c2] = temp;
        }
    }
}

Card Deck::dealCard() {
    if (size() > 0) {
        if (myIndex >= 0 && myIndex < SIZE) {
            Card temp = myCards[myIndex];
            myIndex++;
            return temp;
        }
    } else cout << "Deck is empty" << endl;
}




