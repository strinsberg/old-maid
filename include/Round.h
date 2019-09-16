#ifndef ROUND_H
#define ROUND_H


#include <vector>
#include "Deck.h"
#include "View.h"
#include "Input.h"
#include "Player.h"


/**
 * A round in a card game.
 * @author Steven Deutekom
 * @date sept 16, 2019
 */
class Round {
    public:
        /**
         * Creates a new round object to play a round of the card game.
         *
         * @param d The deck the round is played with.
         * @param v The view object to display information for the round.
         * @param in An object to collect input from the user.
         */
        Round(Deck* d, View* v, Input* in) : deck(d), view(v), input(in) {}
        
        /**
         * Plays the round with the given players.
         * @param players The players playing the round.
         */
        virtual void play(std::vector<Player*>& players)=0;
    
    protected:
        Deck* deck;
        View* view;
        Input* input;
};

#endif
