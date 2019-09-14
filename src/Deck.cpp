#include <vector>
#include "Deck.h"
#include "Card.h"
#include "Suit.h"
#include "Hand.h"


Deck::Deck(int packs) {
    for (int i = 0; i < packs; i++) {
        for (int suit = 1; suit <= 4; suit++) {
            for (int val = 1; val <= 13; val++) {
                Card const* c = new Card(val, static_cast<Suit>(suit));
                cards.push_back(c);
            }
        }
    }
}


Deck::~Deck() {
    for (auto c : cards) {
        delete c;
    }
}


Card const* Deck::getCard(int i) const {
    return cards.at(i);
}

void Deck::shuffle() {
}


std::vector<Hand*> Deck::deal(int hands, int n) {
}


int Deck::size() const {
    return static_cast<int>(cards.size());
}

