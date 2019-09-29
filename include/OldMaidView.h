#ifndef OLD_MAID_VIEW_H
#define OLD_MAID_VIEW_H


#include <vector>
#include "View.h"
#include "Player.h"


/**
 * The view of game related information for Old Maid.
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
    virtual void endRound(std::vector<Player*> players, int winner);
};

#endif
