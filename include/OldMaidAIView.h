#ifndef OLD_MAID_AI_VIEW_H
#define OLD_MAID_AI_VIEW_H


#include <vector>
#include "OldMaidTurnView.h"
#include "Player.h"
#include "Card.h"


/**
 * A view to display only relevant information for an AI turn.
 * Unlike a player turn it is important that the player not see some of
 * the info for an AI's hand etc. Also, in order to speed the game along
 * it is desirable to show only the most relevant information during an
 * AI players turn.
 *
 * @author Steven Deutekom
 * @date sept 29, 2019
 */
class OldMaidAIView : public OldMaidTurnView {
 public:
    OldMaidAIView() : OldMaidTurnView() {}
    virtual ~OldMaidAIView() {}

    virtual void playerInfo(Player* player);
    virtual void takeAction();
    virtual void turnResult(Card* card, bool success);
};

#endif
