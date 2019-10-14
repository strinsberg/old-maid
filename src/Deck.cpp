#include <vector>
#include <algorithm>
#include "Deck.h"
#include "Card.h"
#include "Suit.h"
#include "CardCollection.h"


Deck::Deck(int packs) : cards(new CardCollection()) {
    for (int i = 0; i < packs; i++) {
        for (int suit = 1; suit <= 4; suit++) {
            for (int val = 1; val <= 13; val++) {
                Card const* c = new Card(val, static_cast<Suit>(suit));
                cards->addCard(c);
            }
        }
    }
}


Deck::~Deck() {
    delete cards;
}


Card const* Deck::takeTop() {
    return cards->takeCard(cards->size() - 1);
}


void Deck::shuffle() {
    std::random_device r;
    std::shuffle(cards->begin(), cards->end(), r);
}


std::vector<CardCollection*> Deck::deal(int h, int n) {
    int N = n > 0 ? n : 1000;
    int size = cards->size();

    std::vector<CardCollection*> hands;
    for (int i = 0; i < h; i++)
        hands.push_back(new CardCollection());

    for (int i = 0; i < h * N && i < size; i++)
        hands[i%h]->addCard(takeTop());

    return hands;
}


CardCollection* Deck::getCards() {
    return cards;
}

