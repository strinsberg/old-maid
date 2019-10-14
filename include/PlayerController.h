#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H


#include <vector>
#include "Player.h"
#include "Deck.h"


/**
 * Responsible for player behaviour, input, and output during a card game.
 * Is composed of a Player object. The reason for this class is to allow for
 * controlling players in different ways, such as for AI. It is also useful to
 * put the controller logic in a separate place for a players turn when
 * testing. It is an Abstract class for Mocking and so it may be possible to
 * use it with other games that have similar turn flow. But this may be
 * optimistic to expect.
 *
 * @author Steven Deutekom
 * @date sept 30, 2019
 */
class PlayerController {
 public:
    /**
     * Creates a new player controller. 
     */
    PlayerController() {}

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
    virtual bool takeTurn(Deck* deck, std::vector<Player*> players) = 0;

    /**
     * Update the players hand.
     *
     * Should differ depending on what the game needs. Could be to remove pairs
     * or something more complicated depending on the game. In Old Maid it is
     * used to remove the pairs from the players hand.
     */
    virtual void updateHand() = 0;

    /**
     * Returns the player being controlled.
     * Does not transfer ownership of the Player.
     *
     * @return the player.
     */
    virtual Player* getPlayer() = 0;

    /**
     * Returns whether the player is out of the round or not.
     *
     * @return true if the player is out, otherwise false.
     */
    virtual bool isOut() = 0;

 private:
     PlayerController(const PlayerController&) {}
};

#endif
