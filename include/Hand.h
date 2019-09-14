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

    ~Hand();

	/**
     * Adds a card to the hand.
     *
     * @param card The card to add.
     */
    void addCard(Card const* card);

	/**
     * Finds a given card in the hand and returns the index.
	 *
	 * @param card The card to find.
     * @return the index of the card or -1 if the card is not there.
	 */
    int findCard(Card const* card) const;

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
	 * Returns the number of cards in the hand.
	 *
	 * @return the hand size.
	 */
    int size();

 private:
    std::vector<Card const*> cards;
};

#endif
