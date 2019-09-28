#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include <vector>
#include "CardCollection.h"


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
    CardCollection* getHand();

    /**
     * Sets the players hand to a given hand.
     *
     * @param the new hand.
     */
    void setHand(CardCollection* hand);

    /**
     * Return the players score.
     *
     * @return the score.
     */
    int getScore();

    /**
     * Update the players score by the given amount
     *
     * @param amt The amount to change the score by.
     * @return The new score.
     */
    int updateScore(int amt);

    /**
     * Sorts the players hand by value, suit, or both.
     * For sorting by both the hand is first sorted into groups of suits
     * and then sorted by value.
     *
     * @param byValue Whether or not to sort by value.
     * @param bySuit Whether or not to sort by suit.
     */
    void sortHand(bool byValue, bool bySuit);

 private:
    std::string name;
    CardCollection* hand;
    int score;

    Player(const Player&) {}
};

#endif
