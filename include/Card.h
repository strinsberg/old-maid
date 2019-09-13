#ifndef CARD_H
#define CARD_H


#include "Suit.h"

/**
 * A standard suited playing card.
 *
 * @author Steven Deutekom
 * @date sept 13, 2019
 */
class Card {
 public:
    /**
     * Creates a new card.
     *
     * @param v The value of the card. Must be in range [1, 13].
     * @param s The suit of the card. Must be a valid Suit.
     * @throws InvalidParameterError if v or s are not valid.
     */
    Card(int v, Suit s) : value(v), suit(s) {}

    /**
     * Returns the value of the card.
     * 
     * @return the card's value.
     */
    int getValue() const {return value;}

    /**
     * Returns the suit of the card.
     *
     * @return the card's suit.
     */
    int getSuit() const {return suit;}

 private:
    int value;
    Suit suit;
};

#endif
