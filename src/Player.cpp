#include <string>
#include "Player.h"
#include "Hand.h"

Player::Player(const std::string& n) : name(n), hand(new Hand()) {}

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



int Player::getScore() {}
int Player::updateScore(int amt) {}
void Player::sortHand() {}
std::vector<Card*> Player::updateHand() {}
int Player::handSize() {
}



