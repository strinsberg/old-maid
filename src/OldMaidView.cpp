#include <iostream>
#include <vector>
#include "OldMaidView.h"
#include "Player.h"


void OldMaidView::welcome() {
    std::cout << "=======================" << std::endl;
    std::cout << "= Welcome to Old Maid =" << std::endl;
    std::cout << "=======================" << std::endl << std::endl;

    std::cout << "=== How to Play ===" << std::endl;
    std::cout << "1. At the start of each players turn you will see each";
    std::cout << std::endl;
    std::cout << "   player's current hand size." << std::endl;
    std::cout << "2. On your turn will select the position of a card in the";
    std::cout << std::endl;
    std::cout << "   hand of the player to your right." << std::endl;
    std::cout << "   - If you enter a string or a position larger than the";
    std::cout << std::endl;
    std::cout << "     other players hand size you must choose again.";
    std::cout << std::endl;
    std::cout << "3.  You will be shown the card you picked and if it gave";
    std::cout << std::endl;
    std::cout << "    you a pair." << std::endl;
    std::cout << "    - If you got a pair the paired cards will be removed";
    std::cout << std::endl;
    std::cout << "      from your hand." << std::endl << std::endl;

    std::cout << "-- Players that run out of cards are done." << std::endl;
    std::cout << "-- The last remaining player is the Old Maid." << std::endl;
    std::cout << std::endl;
    std::cout << "** To quit press '<control> c' **" << std::endl;
    std::cout << "====================" << std::endl << std::endl;
}

void OldMaidView::getName() {
    std::cout << "Enter Name: ";
}

void OldMaidView::askNumAI() {
    std::cout << "Enter Opponents (2-5): ";
}


void OldMaidView::beginRound(std::vector<Player*> players) {
    std::cout << std::endl << "=== Begin Round ===" << std::endl;
    std::cout << "The players are:" << std::endl;

    for (auto p : players) {
        std::cout << p->getName() << std:: endl;
    }

    std::cout << std::endl;
}


void OldMaidView::gameStatus(std::vector<Player*> players) {
    std::cout << std::endl << "=== Game Status ===" << std::endl;
    std::cout << "There are " << players.size() << " players:" << std::endl;

    for (auto p : players) {
        std::cout << p->getName() << " has " << p->getHand()->size();
        std::cout << " cards" << std:: endl;
    }

    std::cout << std::endl;
}

void OldMaidView::endRound(std::vector<Player*> players, int winner) {
    std::cout << "============ Game Over =============" << std::endl;
    std::cout << "!!! " << players[winner]->getName();
    std::cout << " is the Old Maid !!!" << std::endl << std::endl;

    std::cout << "*** Thanks For Playing ***" << std::endl;
}
