#ifndef CARD_H
#define CARD_H


#include <string>
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
     * @param s The suit of the card.
     * @throws argument_error if v is out of range.
     */
    Card(int v, Suit s);

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
    Suit getSuit() const {return suit;}

    /**
     * Get a textual representation of the card. ie) val=11 suit=HEART -> JH
     *
     * @return a string of the card value and suit.
     */
    std::string toString() const;


 private:
    int value;
    Suit suit;
};

#endif
