#ifndef OLD_MAID_VIEW_H
#define OLD_MAID_VIEW_H


#include <vector>
#include "View.h"
#include "Player.h"


/**
 * The view of game related information for Old Maid.
 * This holds the specific implementation for a view in an OldMaidGame or Round
 * for things that need to be displayed for the player.
 *
 * @author Steven Deutekom
 * @date sept 29, 2019
 */
class OldMaidView : public View {
 public:
    /**
     * Creates a new OldMaidView.
     */
    OldMaidView() {}
    virtual ~OldMaidView() {}

    virtual void welcome();
    virtual void getName();
    virtual void askNumAI();
    virtual void beginRound(std::vector<Player*> players);
    virtual void gameStatus(std::vector<Player*> players);
    virtual void endRound(std::vector<Player*> players, int winner);
};

#endif
