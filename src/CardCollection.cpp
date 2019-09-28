#include <vector>
#include <string>
#include <sstream>
#include "CardCollection.h"
#include "Card.h"


CardCollection::CardCollection() {}


CardCollection::~CardCollection() {
    for (auto card : cards)
        delete card;
}


void CardCollection::addCard(Card const* card) {
    cards.push_back(card);
}


int CardCollection::findCard(int value, Suit suit) const {
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getValue() == value && cards[i]->getSuit() == suit)
            return i;
    }
    return -1;
}


Card const* CardCollection::takeCard(int i) {
    Card const* card = cards.at(i);
    cards.erase(cards.begin()+i);
    return card;
}


std::vector<Card const*>::iterator CardCollection::begin() {
    return cards.begin();
}


std::vector<Card const*>::iterator CardCollection::end() {
    return cards.end();
}


int CardCollection::size() {
    return static_cast<int>(cards.size());
}


std::string CardCollection::toString() {
    std::stringstream ss;

    for (int i = 0; i < cards.size(); i++) {
        ss << cards[i]->toString();
        if (i < cards.size() - 1)
        ss << ", ";
    }

    return ss.str();
}
