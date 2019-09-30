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
    OldMaidRound(std::vector<PlayerController*> players, Deck* deck,
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
    std::vector<PlayerController*> players;
    Deck* deck;
    Input* input;
    View* view;
};

#endif
