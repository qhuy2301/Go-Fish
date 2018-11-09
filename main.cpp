
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "card.h"
#include "deck.h"

using namespace std;

void initialization(Player &p1,Player &p2, Deck &d);
void play(Player &p1,Player &p2, Deck &d, bool &p1Turn, bool &p2Turn);
void showTable(Player &p1,Player &p2, Deck &d);
void result(Player &p1, Player &p2);

int main() {
    srand(time(0));
    Deck d;
    d.shuffle();
    Player p1("Joe");
    Player p2("Peter");
    bool p1Turn = true;
    bool p2Turn = false;

    initialization(p1,p2,d);

    cout << "Game Starts" << endl;

    while ((p1.getBookSize() < 14) && (p2.getBookSize() < 14) && (p1.getBookSize() +p2.getBookSize() != 26)) {
        Card tempCard1;
        Card tempCard2;
        Card dealtCard;
        if (p1.getHandSize() == 0 && d.size() > 0) {
            cout << p1.getName() << "'s hand is empty and must draw a card" << endl;
            dealtCard = d.dealCard();
            p1.addCard(dealtCard);
            cout << p1.getName() << " draws " << dealtCard << endl;
        }
        if (p1.getHandSize() > 1) {
            for (int i = 0; i < (p1.getHandSize() / 2 + 1); i++) {
                if (p1.checkHandForBook(tempCard1, tempCard2)) p1.bookCards(tempCard1, tempCard2);
            }
        }
        if (p1.getBookSize() == 14) break;

        if (p2.getHandSize() == 0 && d.size() > 0) {
            cout << p2.getName() << "'s hand is empty and must draw a card" << endl;
            dealtCard = d.dealCard();
            p2.addCard(dealtCard);
            cout << p2.getName() << " draws " << dealtCard << endl;
        }
        if (p2.getHandSize() > 1) {
            for (int i = 0; i < (p2.getHandSize() / 2 + 1); i++) {
                if (p2.checkHandForBook(tempCard1, tempCard2)) p2.bookCards(tempCard1, tempCard2);
            }
        }
        if (p2.getBookSize() == 14) break;
        cout << "***************" << endl;
        showTable(p1, p2, d);

        if (p1Turn) play(p1, p2, d, p1Turn, p2Turn);
        else if (p2Turn) play(p2, p1, d, p2Turn, p1Turn);
    }

    cout << "***************" << endl;
    cout << "Game over." << endl;
    showTable(p1,p2,d);
    result(p1,p2);
    return EXIT_SUCCESS;

}

void initialization(Player &p1, Player &p2, Deck &d) {
    while (p1.getHandSize() < 7) {
        p1.addCard(d.dealCard());
    }
    while (p2.getHandSize() < 7) {
        p2.addCard(d.dealCard());
    }
    Card tempCard1;
    Card tempCard2;
    for (int i = 0; i < 4; i++){
        if (p1.checkHandForBook(tempCard1,tempCard2)) p1.bookCards(tempCard1,tempCard2);
        if (p2.checkHandForBook(tempCard1,tempCard2)) p2.bookCards(tempCard1,tempCard2);
    }

}

void showTable(Player &p1, Player &p2, Deck &d) {
    cout << p1.getName() << "'s hand:" << p1.showHand() << ". Hand size: " << p1.getHandSize() << endl;
    cout << p1.getName() << "'s book:" << p1.showBooks() << ". Book size: " << p1.getBookSize() << endl;
    cout << p2.getName() << "'s hand:" << p2.showHand() << ". Hand size: " << p2.getHandSize() << endl;
    cout << p2.getName() << "'s book:" << p2.showBooks() << ". Book size: " << p2.getBookSize() << endl;
    cout << "Cards left: " << d.size() << endl;
    cout << endl;
}

void play(Player &p1,Player &p2, Deck &d, bool &p1Turn, bool &p2Turn) {
    Card tempCard = p1.chooseCardFromHand();
    if (tempCard.getRank() == 1 || tempCard.getRank() == 8) {
        cout << p1.getName() << ": " << "Do you have an " << tempCard.rankString(tempCard.getRank()) << "?" << endl;
    } else {
        cout << p1.getName() << ": " << "Do you have a " << tempCard.rankString(tempCard.getRank()) << "?" << endl;
    }
    if (p2.rankInHand(tempCard)) {
        cout << p2.getName() << ": Yes" << endl;
        bool found = false;
        int s =0;
        while (!found){
            Card sameRank(tempCard.getRank(), (Card::Suit) s);
            if (p2.cardInHand(sameRank)) {
                p1.bookCards(tempCard,p2.removeCardFromHand(sameRank));
                cout << p2.getName() << " gives " << p1.getName() << " " << sameRank << endl;
                cout << endl;
                found = true;
            } else s++;
            p1Turn = true;
            p2Turn = false;
        }
    } else {
        cout << p2.getName() << ": Go Fish!" << endl;
        if (d.size() > 0) {
            Card dealtCard = d.dealCard();
            p1.addCard(dealtCard);
            cout << p1.getName() << " draws " << dealtCard << endl;
            cout << endl;
        }
        p2Turn = true;
        p1Turn = false;
    }
}

void result(Player &p1, Player &p2) {
    if (p1.getBookSize() > p2.getBookSize()) cout << p1.getName() << " wins." << endl;
    else if (p1.getBookSize() < p2.getBookSize()) cout << p2.getName() << " wins." << endl;
    else cout << "It's a tie." << endl;
    cout << "Thanks for playing." << endl;
}







