#ifndef OLD_MAID_VIEW_H
#define OLD_MAID_VIEW_H


#include <iostream>
#include <ostream>
#include <vector>
#include "Card.h"
#include "Player.h"


/**
 * Contains methods to display information for a game of old maid.
 */
class OldMaidView {
 public:
    /**
     * Creates a view object for displaying information for a game of old maid.
     */
    OldMaidView(std::vector<Player*>* players, std::ostream& out = std::cout);

    /**
     * Display the information for the start of a players turn.
     *
     * @param currentPlayer The index of the player whose turn it is.
     */
    virtual void turnInfo(int currentPlayer) const;

    /**
     * Display the prompt for picking a card.
     */
    virtual void pickCard() const;

    /**
     * Display the result of a turn.
     *
     * @param card The card that was picked.
     * @param matched If the card gave the player a match.
     * @param other The card that card is matched with. Default nullptr for
     * when there is no match.
     */
    virtual void result(
        Card const* card, bool matched, Card const* other = nullptr) const;

    /**
     * Display the end of round with the given loser.
     *
     * @param loser The index of the player that lost.
     * @throws out_of_range if loser is >= players->size() or loser < -1.
     */
    virtual void endRound(int loser) const;

 protected:
    std::vector<Player*>* players;
    std::ostream& out;
};

#endif
