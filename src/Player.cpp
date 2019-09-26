#include <string>
#include "Player.h"
#include "Hand.h"

Player::Player(const std::string& n) : name(n), hand(new Hand()), score(0) {}

Player::~Player() {
    delete hand;
}


std::string Player::getName() const {
    return name;
}


Hand* Player::getHand() {
    return hand;
}


void Player::setHand(Hand* h) {
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

void Player::sortHand() {}

std::vector<Card*> Player::updateHand() {}

int Player::handSize() {
}

