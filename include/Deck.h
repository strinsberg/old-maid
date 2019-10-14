#ifndef DECK_H
#define DECK_H


#include <vector>
#include "CardCollection.h"
#include "Card.h"
#include "Suit.h"


/**
 * A deck of standard playing cards. May contain multiple packs of cards.
 *
 * @author Steven Deutekom
 * @date sept 14, 2019
 */
class Deck {
 public:
    /**
     * Create a deck of cards with the given number of packs.
     *
     * Does not include jokers. A pack is the standard 52 cards.
     * The cards will not show what pack they are from so there will be
     * more than one card of each value suit combination if more than 1
     * pack is used.
     *
     * @param packs The number of packs of cards to use for the deck.
     */
    explicit Deck(int packs = 1);

    virtual ~Deck();

    /**
     * Removes and returns the top card of the deck.
     * Transfers ownership of the card.
     *
     * @return the top card.
     */
    virtual Card const* takeTop();

    /**
     * Randomize the ordering of the cards in the deck.
     */
    virtual void shuffle();

    /**
     * Deal out a given number of hands of size n.
     *
     * If n is 0 or is large enough all cards will be dealt and the hand sizes
     * may not be even depending on the number of hands.
     *
     * @param numHands The number of hands to deal out.
     * @param handSize The size of each hand.
     * @return a vector of the hands created.
     */
    virtual std::vector<CardCollection*> deal(int numHands, int handSize = 0);

    /**
     * Return the cards in the deck.
     * Does not transfer ownership.
     *
     * @return the cards.
     */
    virtual CardCollection* getCards();

 private:
    CardCollection* cards;  // Owns this

    Deck(const Deck&) {}
};

#endif
