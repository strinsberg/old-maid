#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include "Hand.h"
#include "Card.h"

bool compareValues(Card const*, Card const*);
bool compareSuits(Card const*, Card const*);
bool compareBoth(Card const*, Card const*);

Hand::Hand() {}


Hand::~Hand() {
    for (auto card : cards)
        delete card;
}


void Hand::addCard(Card const* card) {
    cards.push_back(card);
}

//DEPRICATED//
int Hand::matchCard(int value, Suit suit) const {
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getValue() == value) {
            if (suit != Suit::NONE && cards[i]->getSuit() != suit)
                continue;

            return i;
        }
    }
    return -1;
}


Card const* Hand::getCard(int i) const {
    return cards.at(i);
}


Card const* Hand::takeCard(int i) {
    Card const* card = cards.at(i);
    cards.erase(cards.begin()+i);
    return card;
}


void Hand::sortBy(bool byValue, bool bySuit) {
    if (byValue && bySuit) {
        std::sort(cards.begin(), cards.end(), compareBoth);
    } else if (byValue) {
        std::sort(cards.begin(), cards.end(), compareValues);
    } else if (bySuit) {
        std::sort(cards.begin(), cards.end(), compareSuits);
    }
}

int Hand::size() {
    return static_cast<int>(cards.size());
}


std::string Hand::toString() {
    std::stringstream ss;

    for (int i = 0; i < cards.size(); i++) {
        ss << cards[i]->toString();
        if (i < cards.size() - 1)
        ss << ", ";
    }

    return ss.str();
}


// Private /////////////////////////////////////////////////////

bool compareValues(Card const* a, Card const* b) {
    return a->getValue() < b->getValue();
}


bool compareSuits(Card const* a, Card const* b) {
    return a->getSuit() < b->getSuit();
}


bool compareBoth(Card const* a, Card const* b) {
    if (compareSuits(a, b))
        return true;
    else if (a->getSuit() == b->getSuit())
        return compareValues(a, b);
    return false;
}
