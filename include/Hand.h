#ifndef HAND_H
#define HAND_H


#include <vector>
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

	/**
     * Adds a card to the hand.
     *
     * @param card The card to add.
     */
    void addCard(Card const* card);

	/**
     * Returns the i-th card from the hand.
     *
     * @param i The position of the card to take.
     * @return a pointer to the card.
     * @throws InvalidParameterError if the position is greater
	 * than the hand size or less than 0.
     */
    Card const* takeCard(int i);

	/**
     * Removes a given card from the hand.
	 *
	 * @param card The card to remove.
     * @throws InvalidParameterError if the card does not match any
	 * in the hand.
	 */
    void removeCard(Card const* card);

	/**
	 * Returns the number of cards in the hand.
	 *
	 * @return the hand size.
	 */
    int size();

 private:
    std::vector<Card const*> cards;
};

#endif
