#ifndef OLD_MAID_ROUND_H
#define OLD_MAID_ROUND_H


#include <vector>
#include "Round.h"
#include "Deck.h"
#include "View.h"
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
         * @param view The view object to display information for the round.
         * @param input An object to collect input from the user.
         */
        OldMaidRound(Deck* deck, View* view, Input* input);
        
        /**
         * Plays the round with the given players.
         * @param players The players playing the round.
         */
        void play(std::vector<Player*>& player);
};

#endif
