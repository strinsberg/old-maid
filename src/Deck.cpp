#include <vector>
#include <algorithm>
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

int Deck::findCard(int value, Suit suit) const {
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getValue() == value && cards[i]->getSuit() == suit)
            return i;
    }
    return -1;
}

Card const* Deck::getCard(int i) const {
    return cards.at(i);
}

Card const* Deck::takeCard(int i) {
    Card const* card = cards.at(i);
    cards.erase(cards.begin() + i);
    return card;
}

void Deck::shuffle() {
    std::random_shuffle(cards.begin(), cards.end());
}


std::vector<Hand*> Deck::deal(int h, int n) {
    int N = n > 0 ? n : 1000;
    int size = cards.size();

    std::vector<Hand*> hands;
    for (int i = 0; i < h; i++)
        hands.push_back(new Hand());

    for (int i = 0; i < h * N && i < size; i++) {
        hands[i%h]->addCard(cards.back());
        cards.pop_back();
    }
    return hands;
}


int Deck::size() const {
    return static_cast<int>(cards.size());
}

