#ifndef OLD_MAID_PLAYER_H
#define OLD_MAID_PLAYER_H


#include <vector>
#include "PlayerController.h"
#include "Player.h"
#include "Deck.h"
#include "OldMaidTurnView.h"
#include "Input.h"
#include "CardCollection.h"


/**
 * Controller class for a player during a round of Old Maid..
 * @author Steven Deutekom
 * @date sept 30, 2019
 */
class OldMaidPlayer : public PlayerController {
 public:
    /**
     * Creates a new player controller for a given player.
     *
     * @param player The player to control.
     * @param view The view for a players turn.
     */
    OldMaidPlayer(Player* player, OldMaidTurnView* view);

    virtual ~OldMaidPlayer() {delete input;}

    virtual bool takeTurn(Deck* deck, std::vector<Player*> players);
    virtual Player* getPlayer();
    virtual bool isOut();

 protected:
    Player* player;
    OldMaidTurnView* view;
    Input* input;

    void removePairs(CardCollection* hand);
};

#endif
