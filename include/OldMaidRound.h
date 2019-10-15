#ifndef OLD_MAID_ROUND_H
#define OLD_MAID_ROUND_H


#include <vector>
#include <string>
#include "PlayerController.h"
#include "Deck.h"
#include "View.h"
#include "Input.h"


/**
 * Plays a round of Old Maid.
 * Takes a set of player controllers and can setup and play the round with
 * them. Delegates the taking of turns to the PlayerControllers for simplicity
 * and possible polymorphic behaviour with other player types, like AI.
 *
 * @author Steven Deutekom
 * @date sept 30 2019, oct 14 2019
 */
class OldMaidRound {
 public:
    /**
     * Creates a new round of OldMaid with the given players, deck and view.
     * The player controller vector will be filled with players. In order to
     * allow these players to persist for more than one round they are not
     * deleted. If you want a fresh set of players for a new round please
     * delete all players currently in the vector. Also, Once you have run
     * makePlayers, if you choose to run a game with the same players do not
     * run makePlayers again.
     * 
     * @param players A list of player controllers for the current players.
     * @param deck The deck being used in the round.
     * @param view The view for the round.
     */
    OldMaidRound(std::vector<PlayerController*>* players, Deck* deck,
        View* view);

    virtual ~OldMaidRound();

    /**
     * Get game related info and create the players.
     *
     * @param name The users name.
     * @return false if the entered info is not valid, true otherwise.
     */
    bool makePlayers(std::string name);

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

    /**
     * Set the input.
     * Does transfer ownership.
     *
     * @param in The input to use.
     */
    void setInput(Input* in);

    /**
     * Get the input
     *
     */
    Input* getInput() {return input;}

 private:
    std::vector<PlayerController*>* players;  // Does not own thesee
    Deck* deck;  // Does not own this
    View* view;  // Does not own this
    Input* input;  // Owns this
    std::vector<std::string> aiNames{
        "Bill", "Jane", "Wendy", "Max", "Shane", "Alex"};

    /**
     * Returns the player data objects from players.
     * Optionally only returns players that are still playing the game.
     *
     * @param stillPlaying Whether to return all players or only the ones
     * still playing the game. Default false.
     * @return the player data objects for players still in the game.
     */
    std::vector<Player*> getPlayers(bool stillPlaying = false);

    OldMaidRound(const OldMaidRound&) {}
};

#endif
