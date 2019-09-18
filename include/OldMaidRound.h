#ifndef OLD_MAID_ROUND_H
#define OLD_MAID_ROUND_H


#include <vector>
#include "Round.h"
#include "Deck.h"
#include "OldMaidView.h"
#include "Input.h"
#include "Player.h"


/**
 * A round for a game of old maid.
 * @author Steven Deutekom
 * @date setp 16, 2019
 */
class OldMaidRound : public Round {
 public:
    /**
     * Creates a new round object to play a round of old maid.
     * @param deck The deck the round is played with.
     * @param players The players for the round.
     * @param input An object to collect input from the user.
     * @param view The view object to display information for the round.
     */
    OldMaidRound(Deck* deck, std::vector<Player*>* players, Input* input,
        OldMaidView* view);

    /**
     * Plays the round with the given players.
     */
    int play();
 
 protected:
    OldMaidView* view;
};

#endif
