#ifndef OLD_MAID_VIEW_H
#define OLD_MAID_VIEW_H


#include <iostream>
#include <ostream>
#include <vector>
#include "View.h"
#include "Hand.h"
#include "Player.h"
#include "OldMaidRound.h"


/**
 * Contains methods to display information for a game of old maid.
 */
class OldMaidView : public View {
 public:
    /**
     * Creates a view object for displaying information for a game of old maid.
     */
    OldMaidView(vector<Player*>* players, std::ostream& out = std::cout);

    /**
     * Display the information for the start of a players turn.
     *
     * @param currentPlayer The index of the player whose turn it is.
     */
    void playerInfo(int currentPlayer) const;

    /**
     * Display the prompt for picking a card.
     */
    void pickCard() const;

    /**
     * Display the result of a turn.
     *
     * @param card The card that was picked.
     * @param matched If the card gave the player a match.
     */
    void result(Card const* card, bool matched) const;

    /**
     * Display the end of round with the given loser.
     *
     * @param loser The index of the player that lost.
     */
    void endRound(int loser) const;

 protected:
    vector<Player*>* players;
};

#endif
