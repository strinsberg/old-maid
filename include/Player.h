#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include <vector>
#include "CardCollection.h"


/**
 * A player model in a card game with 1 hand of cards.
 * Keeps track of players name, cards, and score.
 *
 * @author Steven Deutekom
 * @date sept 15 2019, oct 14 2019
 */
class Player {
 public:
    /**
     * Creates a new player with a given name.
     *
     * @param name The players name.
     */
    explicit Player(const std::string& name);

    virtual ~Player();

    /**
     * Returns the players name.
     *
     * @return the players name.
     */
    virtual std::string getName() const;

    /**
     * Returns a pointer to the player's hand.
     * Does not transfer ownership of the hand.
     *
     * @param the players hand.
     */
    virtual CardCollection* getHand();

    /**
     * Sets the players hand to a given hand.
     * Transfers ownership of the hand.
     *
     * @param the new hand.
     */
    virtual void setHand(CardCollection* hand);

    /**
     * Return the players score.
     *
     * @return the score.
     */
    virtual int getScore();

    /**
     * Update the players score by the given amount
     *
     * @param amt The amount to change the score by.
     * @return The new score.
     */
    virtual int updateScore(int amt);

    /**
     * Sorts the players hand by value, suit, or both.
     * For sorting by both the hand is first sorted into groups of suits
     * and then sorted by value.
     *
     * @param byValue Whether or not to sort by value.
     * @param bySuit Whether or not to sort by suit.
     */
    virtual void sortHand(bool byValue, bool bySuit);

 protected:
    std::string name;
    CardCollection* hand;  // Owns this
    int score;

 private:
    Player(const Player&) {}
};

#endif
