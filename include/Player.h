#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include "Hand.h"


/**
 * A player in a card game with 1 hand of cards.
 * @author Steven Deutekom
 * @date sept 15, 2019
 */
class Player {
 public:
    /**
     * Creates a new player with a given name.
     *
     * @param name The players name.
     */
    explicit Player(const std::string& name);

    ~Player();

    /**
     * Returns the players name.
     *
     * @return the players name.
     */
    std::string getName() const;

    /**
     * Returns a pointer to the player's hand.
     *
     * @param the players hand.
     */
    Hand* getHand();

    /**
     * Sets the players hand to a given hand.
     *
     * @param the new hand.
     */
    void setHand(Hand* hand);

 private:
    std::string name;
    Hand* hand;

    Player(const Player&) {}
};

#endif
