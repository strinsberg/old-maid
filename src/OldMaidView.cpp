#include <iostream>
#include <vector>
#include "OldMaidView.h"
#include "Player.h"


void OldMaidView::welcome() {
    std::cout << "==== Old Maid ====" << std::endl << std::endl;
}

void OldMaidView::getName() {
    std::cout << "Enter Name: ";
}

void OldMaidView::askNumAI() {
    std::cout << "Enter Opponents (2-5): ";
}

void OldMaidView::beginRound(std::vector<Player*> players) {
    std::cout << std::endl << "=== Begin Round ===" << std::endl;
}


void OldMaidView::gameStatus(std::vector<Player*> players) {
    std::cout << std::endl << "=== Game Status ===" << std::endl;
}

void OldMaidView::endRound(std::vector<Player*> players, int winner) {
    std::cout << std::endl << players[winner]->getName();
    std::cout << " is the Old Maid" << std::endl;
}
