#ifndef ROUND_H
#define ROUND_H


#include <vector>
#include "Deck.h"
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
     * @param p The players for the round.
     * @param in An object to collect input from the user.
     */
    Round(Deck* d, std::vector<Player*>* p, Input* in)
        : deck(d), players(p), input(in) {}

    /**
     * Plays the round with the given players.
     * @return the index of the player who won or lost the round.
     */
    virtual int play() = 0;

 protected:
    Deck* deck;
    std::vector<Player*>* players;
    Input* input;
};

#endif
