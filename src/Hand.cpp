#include <vector>
#include "Hand.h"
#include "Card.h"


Hand::Hand() {}

Hand::~Hand() {
    for (auto card : cards)
        delete card;
}

void Hand::addCard(Card const* card) {
}

Card const* Hand::takeCard(int i) {
    return nullptr;
}

void Hand::removeCard(Card const* card) {
}

int Hand::size() {
    return static_cast<int>(cards.size());
}
