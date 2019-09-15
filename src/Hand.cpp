#include <vector>
#include <sstream>
#include <algorithm>
#include "Hand.h"
#include "Card.h"


Hand::Hand() {}


Hand::~Hand() {
    for (auto card : cards)
        delete card;
}


void Hand::addCard(Card const* card) {
    cards.push_back(card);
}


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
