#ifndef OLD_MAID_TURN_VIEW_H
#define OLD_MAID_TURN_VIEW_H


#include <vector>
#include <string>
#include "Player.h"
#include "Card.h"


/**
 * A view to display information during a players turn.
 *
 * @author Steven Deutekom
 * @date sept 29 2019, oct 14 2019
 */
class OldMaidTurnView {
 public:
    /**
     * Creates a new view for the given player.
     *
     * @param player The player whose turn information will be displayed.
     */
    explicit OldMaidTurnView(Player* player);

    virtual ~OldMaidTurnView() {}

    /**
     * Displays player information that should come at the start of a turn.
     *
     * @param players The players participating in the round.
     */
    virtual void turnInfo();

    /**
     * Display information for actions a player will take on their turn.
     *
     * @param opponent The player to take a card from.
     */
    virtual void takeAction(Player* opponent);

    /**
     * Display info and a message if the player gives bad input.
     *
     * @param message The error message to display.
     */
    virtual void badInput(std::string message);

    /**
     * Display the result of a turn.
     */
    virtual void turnResult(Card const* card, bool success);

    /**
     * Display Press ENTER to continue.
     */
    virtual void wait();

 protected:
    Player* player;  // Does not own this.

    OldMaidTurnView(const OldMaidTurnView&);
};

#endif
