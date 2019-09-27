#ifndef HAND_H
#define HAND_H


#include <vector>
#include <string>
#include "Card.h"


/**
 * A Collection of cards.
 *
 * @author Steven Deutekom
 * @date sept 13, 2019
 */
class Hand {
 public:
    /**
     * Creates an empty hand
     */
    Hand();

    ~Hand();

    /**
     * Adds a card to the hand.
     *
     * @param card The card to add.
     */
    void addCard(Card const* card);

    /**
     * (Depricated) Finds a matching card in a hand.
     * 
     * If suit is ignored it will return the first card with the given value.
     * If there are more than one available matches it will only return the
     * index of the first one it finds.
     *
     * @param value The value of the card to find.
     * @param suit The suit of the card to find.
     * @return the index of the card or -1 if there is no match.
     */
    int matchCard(int value, Suit suit = Suit::NONE) const;

    /**
     * Access a card at the given index.
     *
     * @param card The index of the card to access.
     * @return the card.
     * @throws invalud_argument if the position is greater
     * than the hand size or less than 0.
     */
    Card const* getCard(int i) const;

    /**
     * Returns the i-th card from the hand.
     *
     * @param i The position of the card to take.
     * @return a pointer to the card.
     * @throws invalud_argument if the position is greater
     * than the hand size or less than 0.
     */
    Card const* takeCard(int i);

    /**
     * Sort the hand.
     * If both parameters are true then the hand will be sorted like so
     * AH 4H 2S 7S 5C KC.
     *
     * @param byValue Whether to sort the hand by value. Eg) 112233.
     * @param bySuit Whether to sort the hand by suit. Eg) HHSSSCC.C
     */
    void sortBy(bool byValue, bool bySuit);

    /**
     * Returns the number of cards in the hand.
     *
     * @return the hand size.
     */
    int size();

    /**
     * Return a textual representation of the hand.
     *
     * @return a string of cards in the hand.
     */
    std::string toString();

 private:
    std::vector<Card const*> cards;
};

#endif
