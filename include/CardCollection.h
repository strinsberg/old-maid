#ifndef CARD_COLLECTION_H
#define CARD_COLLECTION_H


#include <vector>
#include <string>
#include "Card.h"


/**
 * A Collection of cards.
 *
 * @author Steven Deutekom
 * @date sept 28, 2019
 */
class CardCollection {
 public:
    /**
     * Creates an empty collection
     */
    CardCollection();

    ~CardCollection();

    /**
     * Adds a card to the collection.
     *
     * @param card The card to add.
     */
    void addCard(Card const* card);

    /**
     * Find a card in the collection given a value and suit.
     *
     * @param value The value of the card.
     * @param suit The suit of the card.
     * @return the index of the card in the collection or -1.
     */
    int findCard(int value, Suit suit) const;

    /**
     * Returns the i-th card from the collection.
     *
     * @param i The position of the card to take.
     * @return a pointer to the card.
     * @throws invalud_argument if the position is greater
     * than the collection size or less than 0.
     */
    Card const* takeCard(int i);

    /**
     * Return an iterator to the beginning of the collection.
     *
     * @return iterator to the first element.
     */
    std::vector<Card*>::iterator begin();

    /**
     * Return an iterator to the end of the collection.
     *
     * @return iterator to one past the last element.
     */
    std::vector<Card*>::iterator end();

    /**
     * Returns the number of cards in the collection.
     *
     * @return the collection size.
     */
    int size();

    /**
     * Return a textual representation of the collection.
     *
     * @return a string of cards in the collection.
     */
    std::string toString();

 private:
    std::vector<Card const*> cards;
};

#endif
