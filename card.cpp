#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include <string>
#include <sstream>

using namespace std;

// Default Constructor
Card::Card() {
    myRank = 1;
    mySuit = spades;
}

// Constructor: setting rank and suit of Card
Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

// sameSuitAs Function
bool Card::sameSuitAs(const Card &c) const {
    return (mySuit == c.mySuit);
}

// getRank Function
// returns rank of card
int Card::getRank() const {
    return myRank;
}


// suitString Function
// returns suit of card
string Card::suitString(Card::Suit s) const {
    if (s == spades)
        return "s";
    else if (s == clubs)
        return "c";
    else if (s == diamonds)
        return "d";
    else
        return "h";
}

// rankString Function
// returns rank of card (i.e. A, J, Q)
string Card::rankString(int r) const {
    if (r>1 && r<11) {
    	stringstream ss;
    	ss << r;
    	return ss.str();
    }
    else if (r == 1)
        return "A";
    else if (r == 11)
        return "J";
    else if (r == 12)
        return "Q";
    else
        return "K";
}

// Overide operator ==
bool Card::operator == (const Card &rhs) const {
    return (myRank == rhs.myRank && mySuit == rhs.mySuit);
}

// Overide operator !=
bool Card::operator!=(const Card &rhs) const {
    return (myRank != rhs.myRank);
}

// toString Function
string Card::toString() const {
    string cardStr = rankString(myRank) + suitString(mySuit);
    return cardStr;
}

ostream& operator << (ostream& out, const Card& c){
    out << c.toString();
    return out;
}
