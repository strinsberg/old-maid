#ifndef OLD_MAID_VIEW_H
#define OLD_MAID_VIEW_H


#include <iostream>
#include <ostream>
#include <vector>
#include "View.h"
#include "Hand.h"
#include "Player.h"


/**
 * Contains methods to display information for a game of old maid.
 */
class OldMaidView : public View {
 public:
    /**
     * Creates a view object for displaying information for a game of old maid.
     */
    OldMaidView(std::ostream& out = std::cout);

    /**
     * Displays the contents of a players hand.
     * @param hand The hand to display.
     */
    void displayHand(Hand* hand);

    /**
     * Displays info about the players.
     * The main purpose is to show how many cards each player has left.
     * @param players The players to show information for.
     */
    void displayPlayers(const std::vector<Player*>& players);
};

#endif
