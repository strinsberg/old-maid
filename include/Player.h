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
     * Sorts the hand with handSorter.
     * Players in each game will have a different hand sorter depending on
     * what ordering is best. For OldMaid ordering by value is enough. For
     * others ordering might be more complicated.
     */
    void sortHand();
    
    /**
     * Updates the state of the hand using handUpdater.
     * For example if a game requires removing pairs the updater will remove
     * all the pairs from the hand. The removed cards will be returned in a
     * vector.
     * 
     * @return A vector of all the cards removed during the update, if any.
     */
    std::vector<Card*> updateHand();

    /**
     * Return the size of the players hand.
     *
     * @return hand size.
     */
    int handSize();

 private:
    std::string name;
    Hand* hand;
    int score;
    //HandSorter* handSorter;
    //HandUpdater* handUpdater;

    Player(const Player&) {}
};

#endif
