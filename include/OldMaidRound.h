#ifndef OLD_MAID_ROUND_H
#define OLD_MAID_ROUND_H


#include <vector>
#include "PlayerController.h"
#include "Deck.h"
#include "View.h"
#include "Input.h"


/**
 * Plays a round of Old Maid.
 * @author Steven Deutekom
 * @date sept 30, 2019
 */
class OldMaidRound {
 public:
    /**
     * Creates a new round of OldMaid with the given players, deck and view.
     */
    OldMaidRound(std::vector<PlayerController*>* players, Deck* deck,
        View* view);

    virtual ~OldMaidRound();

    /**
     * Sets up the round shuffling the deck and dealing hands to the players.
     */
    void setup();

    /**
     * Plays the round of OldMaid.
     *
     * @return the index of the winning player.
     */
    int play();

 private:
    std::vector<PlayerController*>* players;
    Deck* deck;
    Input* input;
    View* view;

    /**
     * Returns the player data objects from players.
     * Optionally only returns players that are still playing the game.
     *
     * @param stillPlaying Whether to return all players or only the ones
     * still playing the game. Default false.
     * @return the player data objects for players still in the game.
     */
    std::vector<Player*> getPlayers(bool stillPlaying = false);

    /**
     * Check to see if the game is over yet and return the remaining player.
     * In old maid the remaining player is the loser and the Old Maid.
     *
     * @param inGame A vector of player indexes. True for still playing and
     * false if the player is out of cards.
     * @return The remaining player if there is only one still playing,
     * otherwise -1.
     */
    int gameStatus(std::vector<bool> inGame);
};

#endif
