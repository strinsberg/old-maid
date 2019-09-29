#ifndef VIEW_H
#define VIEW_H


#include <vector>
#include "Player.h"


/**
 * Interface for a simple game view.
 * @author Steven Deutekom
 * @date sept 29, 2019
 */
class View {
 public:
    virtual ~View() {}

    /**
     * Displays information to welcome the player to the specific game.
     */
    virtual void welcome() = 0;
    
    /**
     * Displaysy text to ask a player for their name.
     */
    virtual void getName() = 0;
    
    /**
     * Displays text to ask how many AI opponents to include.
     */
    virtual void askNumAI() = 0;

    /**
     * Displays information to begin a round.
     *
     * @param players The players participating in the round.
     */
    virtual void beginRound(std::vector<Player*> players) = 0;

    /**
     * Displays information at the end of a round.
     *
     * @param players The players participating in the round.
     * @param winner The index of the winning player.
     */
    virtual void endRound(std::vector<Player*> players, int winner) = 0;
};

#endif
