#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H


#include <vector>
#include "Player.h"
#include "Deck.h"
#include "OldMaidTurnView.h"
#include "Input.h"


/**
 * Responsible for player behaviour, input, and output during a card game.
 * @author Steven Deutekom
 * @date sept 30, 2019
 */
class PlayerController {
 public:
    /**
     * Creates a new player controller for a given player.
     *
     * @param p The player to control.
     */
    PlayerController(Player* p, OldMaidTurnView* v);

    virtual ~PlayerController() {}

    /**
     * Takes a players turn.
     * The bool return may differ in different games. In Old Maid when a player
     * is out the game continues, but in others a player going out may end the
     * game.
     *
     * @param deck The deck being used in the round.
     * @param players The players participating in the round.
     * @return whether or not the player is now out of the game.
     */
    virtual bool takeTurn(Deck* deck, std::vector<Player*> players);

    /**
     * Returns the player being controlled.
     *
     * @return the player.
     */
    virtual Player* getPlayer();

    /**
     * Returns whether the player is out of the round or not.
     *
     * @return true if the player is out, otherwise false.
     */
    virtual bool isOut();

 protected:
    Player* player;
    OldMaidTurnView* view;
    Input* input;
};

#endif
