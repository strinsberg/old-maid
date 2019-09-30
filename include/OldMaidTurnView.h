#ifndef OLD_MAID_TURN_VIEW_H
#define OLD_MAID_TURN_VIEW_H


#include <vector>
#include <string>
#include "Player.h"
#include "Card.h"


/**
 * A view to display information during a players turn.
 * @author Steven Deutekom
 * @date sept 29, 2019
 */
class OldMaidTurnView {
 public:
    OldMaidTurnView() {}
    virtual ~OldMaidTurnView() {}

    /**
     * Displays information that should come at the start of a turn.
     *
     * @param players The players participating in the round.
     */
    virtual void turnInfo(std::vector<Player*> players);

    /**
     * Displays player specific information for a player's turn.
     *
     * @param player The player taking their turn.
     */
    virtual void playerInfo(Player* player);

    /**
     * Display information for actions a player will take on their turn.
     */
    virtual void takeAction();

    /**
     * Display info and a message if the player gives bad input.
     *
     * @param message The error message to display.
     */
    virtual void badInput(std::string message);

    /**
     * Display the result of a turn.
     */
    virtual void turnResult(Card* card, bool success);
};

#endif
