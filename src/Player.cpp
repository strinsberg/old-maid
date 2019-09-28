#include <string>
#include <algorithm>
#include "Player.h"
#include "CardCollection.h"
#include "Suit.h"


// Declare sort functions for sorting a hand
bool compareValues(Card const*, Card const*);
bool compareSuits(Card const*, Card const*);
bool compareBoth(Card const*, Card const*);


Player::Player(const std::string& n)
    : name(n), hand(new CardCollection()), score(0) {}


Player::~Player() {
    delete hand;
}


std::string Player::getName() const {
    return name;
}


CardCollection* Player::getHand() {
    return hand;
}


void Player::setHand(CardCollection* h) {
    delete hand;
    hand = h;
}


int Player::getScore() {
    return score;
}

int Player::updateScore(int amt) {
    score += amt;
    return score;
}


void Player::sortHand(bool byValue, bool bySuit) {
    if (byValue && bySuit) {
        std::sort(hand->begin(), hand->end(), compareBoth);
    } else if (byValue) {
        std::sort(hand->begin(), hand->end(), compareValues);
    } else if (bySuit) {
        std::sort(hand->begin(), hand->end(), compareSuits);
    }
}


// Compareison functions for sorting the hand ////////////////////////////

bool compareValues(Card const* a, Card const* b) {
    return a->getValue() < b->getValue();
}


bool compareSuits(Card const* a, Card const* b) {
    return a->getSuit() < b->getSuit();
}


bool compareBoth(Card const* a, Card const* b) {
    if (compareSuits(a, b))
        return true;
    else if (a->getSuit() == b->getSuit())
        return compareValues(a, b);
    return false;
}

