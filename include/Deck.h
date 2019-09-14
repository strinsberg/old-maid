#ifndef DECK_H
#define DECK_H


#include <vector>
#include "Card.h"
#include "Hand.h"


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
    Deck(int packs = 1);
    
    ~Deck();

    /**
     * Get a card from the deck at position i.
     *
     * @param i The index of the card to get.
     * @return the card at position i.
     * @throw out_of_range if i < 0 or i > deck.size() - 1.
     */
    Card const* getCard(int i) const;

    /**
     * Randomize the ordering of the cards in the deck.
     */
    void shuffle();

    /**
     * Deal out a given number of hands of size n.
     *
     * If n is 0 or is large enough all cards will be dealt and the hand sizes
     * may not be even depending on the number of hands.
     *
     * @param hands The number of hands to deal out.
     * @param n The size of each hand.
     * @return a vector of the hands created.
     */
    std::vector<Hand*> deal(int hands, int n = 0);

    /**
     * The number of cards currently in the deck.
     *
     * @return the size of the deck.
     */
    int size() const;

 private:
    std::vector<Card const*> cards;
};

#endif
