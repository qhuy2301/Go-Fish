#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "player.h"


using namespace std;

Player::Player(){
    myName = "";
}

void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    removeCardFromHand(c1);
    myBook.push_back(c2);
    removeCardFromHand(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2){
    vector <Card>::iterator iter1;
    for (iter1 = myHand.begin(); iter1 < myHand.end(); iter1++){
        vector <Card>::iterator iter2;
        for (iter2 = iter1+1; iter2 <myHand.end(); iter2++) {
            Card card1 = *iter1;
            Card card2 = *iter2;
            if (card1.getRank() == card2.getRank()) {
                c1 = card1;
                c2 = card2;
                return true;
            }
        }
    }
    return false;
}

bool Player::rankInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == c.getRank()) return true;
    }
    return false;
}

Card Player::chooseCardFromHand() const{
    int i = rand() % myHand.size();
    return myHand[i];
}

bool Player::cardInHand(Card c) const{
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i] == c) {
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c){
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i] == c) {
            Card temp = myHand[i];
            myHand.erase(myHand.begin()+i);
            return temp;
        }
    }
}

string Player::showHand() const{
    string playerHand;
    for (int i = 0; i < myHand.size(); i++) {
        playerHand += " " + myHand[i].toString();
    }
    return playerHand;
}

string Player::showBooks() const{
    string playerBook;
    for (int i = 0; i < myBook.size(); i+=2) {
        playerBook += " " + myBook[i].toString() + "-" + myBook[i+1].toString();
    }
    return playerBook;
}

int Player::getHandSize() const{
    return myHand.size();
}

int Player::getBookSize() const{
    return myBook.size()/2;
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
    return (c1.getRank() == c2.getRank());
}

bool Player::sameRankInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == c.getRank()) return true;
    }
    return false;
}
