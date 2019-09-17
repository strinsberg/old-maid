#include <string>
#include "Player.h"
#include "Hand.h"

Player::Player(const std::string& n) : name(n), hand(nullptr) {}

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
