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

int Hand::findCard(Card const* card) const {
}

Card const* Hand::getCard(int i) const {
}

Card const* Hand::takeCard(int i) {
}

int Hand::size() {
    return static_cast<int>(cards.size());
}
