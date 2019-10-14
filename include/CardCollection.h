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
    virtual void addCard(Card const* card);

    /**
     * Find a card in the collection given a value and suit.
     *
     * @param value The value of the card.
     * @param suit The suit of the card.
     * @return the index of the card in the collection or -1.
     */
    virtual int findCard(int value, Suit suit) const;

    /**
     * Returns the i-th card from the collection.
     *
     * @param i The position of the card to take.
     * @return a pointer to the card.
     * @throws invalud_argument if the position is greater
     * than the collection size or less than 0.
     */
    virtual Card const* getCard(int i);

    /**
     * Removes and returns the i-th card from the collection.
     *
     * @param i The position of the card to take.
     * @return a pointer to the card.
     * @throws invalud_argument if the position is greater
     * than the collection size or less than 0.
     */
    virtual Card const* takeCard(int i);

    /**
     * Remove cards at all indexes in a given list.
     *
     * @precondition idxs must be sorted in increasing order.
     *
     * @param idxs A list of cards to remove.
     * @return a list of the card pointers that were removed.
     */
    virtual std::vector<Card const*> takeAllCards(std::vector<int> idxs);

    /**
     * Return an iterator to the beginning of the collection.
     *
     * @return iterator to the first element.
     */
    virtual std::vector<Card const*>::iterator begin();

    /**
     * Return an iterator to the end of the collection.
     *
     * @return iterator to one past the last element.
     */
    virtual std::vector<Card const*>::iterator end();

    /**
     * Returns the number of cards in the collection.
     *
     * @return the collection size.
     */
    virtual int size();

    /**
     * Return a textual representation of the collection.
     *
     * @return a string of cards in the collection.
     */
    virtual std::string toString();

 protected:
    std::vector<Card const*> cards;
};

#endif
